/*----------------------------------------------------------------------------*/
/**
*   \file         lin_diagnose.c
*   \brief        C-implementation of lin bus diagnostic.
*/
/*----------------------------------------------------------------------------*/
/**
*   \addtogroup   doc_lin_diag
*   \{
*   \internal
*   \endinternal
*
*/
/*----------------------------------------------------------------------------*/

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------

/*----------------------------------------------------------------------------*/
/** 
* \file         lin_diagnose.c
* \brief        LIN diagnose functionality
* \details      user callback functions to be able to perform a LIN specific diagnose
* \date         20151019
* \author       Geissler
*
*/
/*----------------------------------------------------------------------------*/
#include "lin_diagnose.h"

// --------------------------------------------------------------------------------
// LIN diagnose (slave implementation)
// --------------------------------------------------------------------------------

#if (SLAVE_DIAGNOSTICS_ENABLED	==	TRUE)

static uint8_t mgl_lin_dig_request_sid = 0x00;
static uint8_t mgl_lin_dig_request_pci = 0x00;

void lin_diag_prepare_positive_response(uint8_t nad, uint8_t sid, uint8_t length) // note: max length is 5!
{
	ext_ary_lin0_diag_slave_response_data[0] = nad;				// node address
    ext_ary_lin0_diag_slave_response_data[1] = length + 1;      // PCI
    ext_ary_lin0_diag_slave_response_data[2] = (sid | 0x40);   	// RSID = SID | 0x40

    // set the remaining buffer to 0xFF
    (void)memset( &(ext_ary_lin0_diag_slave_response_data[3]), 0xFF, 5 );
}


uint8_t read_by_id( uint8_t data_id )
{
	uint8_t nrc = 0x00;

    // which DID?
    switch ( data_id )
    {
		case DID_LIN_PRODUCT_ID: // DID = 0x01
			lin_diag_prepare_positive_response(LIN_INITIAL_NAD, READ_BY_DATA_IDENTIFIER_SID, 5);

			ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_0] = ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][0];
			ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_1] = ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][1];
			ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_2] = ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][2];
			ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_3] = ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][3];
			ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_4] = ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][4];

			break;

    	case DID_SERIAL_NUMBER: // DID = 0x01
    		lin_diag_prepare_positive_response(LIN_INITIAL_NAD, READ_BY_DATA_IDENTIFIER_SID, 4);

    		ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_0] = 0x12;
    		ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_1] = 0x34;
    		ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_2] = 0x56;
    		ext_ary_lin0_diag_slave_response_data[LIN_DIAG_PAYLOAD_3] = 0x78;

    		break;


    	default:
    		nrc = NRC_SERVICE_NOT_SUPPORTED;
    		break;
    }

	return nrc;
}


void lin_diag_negative_response(uint8_t sid, uint8_t nrc)
{
	ext_ary_lin0_diag_slave_response_data[0] = LIN_INITIAL_NAD;     	// Node Address (NAD)
	ext_ary_lin0_diag_slave_response_data[1] = NEGATIVE_RESPONSE_LEN;  	// PCI
	ext_ary_lin0_diag_slave_response_data[2] = NEGATIVE_RESPONSE_SID;	//

	ext_ary_lin0_diag_slave_response_data[3] = sid;						// Requested Service ID
	ext_ary_lin0_diag_slave_response_data[4] = nrc;						// Negative Response Code (NRC)
	ext_ary_lin0_diag_slave_response_data[5] = 0xFF;
	ext_ary_lin0_diag_slave_response_data[6] = 0xFF;
	ext_ary_lin0_diag_slave_response_data[7] = 0xFF;
}
#endif




/*----------------------------------------------------------------------------*/
/** 
* \internal
*   
* \endinternal

*/
void lin_diag_master_request(uint8_t lin_module)
{
    // Here you can write your code

    // --------------------------------------------------------------------------------
    // For example a received go to sleep command:
    // --------------------------------------------------------------------------------
    // check for a go to sleep command from master
    // {0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    // --------------------------------------------------------------------------------

#if (SLAVE_DIAGNOSTICS_ENABLED	==	TRUE)
    if( 	(ext_ary_lin0_diag_master_request_data[0] == 0x00) && (ext_ary_lin0_diag_master_request_data[1] == 0xFF)
        &&  (ext_ary_lin0_diag_master_request_data[2] == 0xFF) && (ext_ary_lin0_diag_master_request_data[3] == 0xFF)
        &&  (ext_ary_lin0_diag_master_request_data[4] == 0xFF) && (ext_ary_lin0_diag_master_request_data[5] == 0xFF)
        &&  (ext_ary_lin0_diag_master_request_data[6] == 0xFF) && (ext_ary_lin0_diag_master_request_data[7] == 0xFF)
        )
    {
        // --------------------------------------------------------------------------------
        // a go to sleep command from master was received
        // --------------------------------------------------------------------------------
		modulhardwarecode_sleep();
    }
    else
    {
    	// check NAD
        if( (ext_ary_lin0_diag_master_request_data[0] == LIN_INITIAL_NAD) || (ext_ary_lin0_diag_master_request_data[0] == LIN_WILD_CARD_ID) )
        {
            // read request -> also compare supplier ID and function ID
            uint16_t supplier_id = ext_ary_lin0_diag_master_request_data[4] | (ext_ary_lin0_diag_master_request_data[5] << 8);
            uint16_t function_id = ext_ary_lin0_diag_master_request_data[6] | (ext_ary_lin0_diag_master_request_data[7] << 8);

            uint16_t supplier_id_predefined = 	  ( ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][PROD_ID_SUPPLIER_ID_MSB] << 8 )
            									| ( ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][PROD_ID_SUPPLIER_ID_LSB] );

            uint16_t function_id_predefined = 	  ( ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][PROD_ID_FUNCTION_ID_MSB] << 8 )
            									| ( ext_ptr_ary_lin_diag_product_id[LIN_BUS_0][PROD_ID_FUNCTION_ID_LSB] );


        	//  For full LIN compliance, also check Supplier and Function ID
            if (    ( (supplier_id_predefined == supplier_id) || (LIN_SUPPLIER_ID_WILD_CARD == supplier_id) )
                 && ( (function_id_predefined == function_id) || (LIN_FUNCTION_ID_WILD_CARD == function_id) ) )
            {
				// --------------------------------------------------------------------------------
				// save SID
				// --------------------------------------------------------------------------------
				mgl_lin_dig_request_sid = ext_ary_lin0_diag_master_request_data[2];
				// --------------------------------------------------------------------------------
				// save PCI
				// --------------------------------------------------------------------------------
				mgl_lin_dig_request_pci = ext_ary_lin0_diag_master_request_data[1];

				ext_current_slave_state[lin_module] = SLAVE_STATE_TRANSMIT_RESPONSE;
            }
            else
            {
            	ext_current_slave_state[lin_module] = SLAVE_STATE_IDLE;
            }

        }
        else
        {
        	ext_current_slave_state[lin_module] = SLAVE_STATE_IDLE;
        }
    }
#else
    // always set to IDLE if not used
    ext_current_slave_state[lin_module] = SLAVE_STATE_IDLE;
#endif
}


/*----------------------------------------------------------------------------*/
/** 
* \internal
*   
* \endinternal
*/
uint8_t lin_diag_slave_response(uint8_t lin_module)
{
#if (SLAVE_DIAGNOSTICS_ENABLED	==	TRUE)
    uint8_t ret_status = LIN_STATE_ERROR;
    uint8_t nrc	= 0x00;
    
    // only execute if a master request has been received before
    if ( (ext_current_slave_state[lin_module] == SLAVE_STATE_TRANSMIT_RESPONSE) )
    {
    	if ( mgl_lin_dig_request_sid == READ_BY_DATA_IDENTIFIER_SID )
    	{
    		nrc = read_by_id( ext_ary_lin0_diag_master_request_data[3] );

    		// an error occurred?
    		if (nrc != 0)
    		{
    			// send negative response
    			lin_diag_negative_response(mgl_lin_dig_request_sid, nrc);
    		}
    	}
    	else
    	{
    		// send negative response service not supported
    		lin_diag_negative_response(mgl_lin_dig_request_sid, NRC_SERVICE_NOT_SUPPORTED);
    	}

		ret_status = LIN_STATE_SUCCESS;
    }
    
    return ret_status;
#else
    // --------------------------------------------------------------------------------
    // in the case of no using to get no compiler INFO set all as (void)xy;
    // --------------------------------------------------------------------------------
    (void)lin_module;


    return LIN_STATE_ERROR;
#endif
}









/** \}*/

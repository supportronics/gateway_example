#ifndef _LIN_DIAGNOSE_H_
#define _LIN_DIAGNOSE_H_

/*----------------------------------------------------------------------------*/
/**
*   \file         lin_diagnose.h
*   \brief        C-Declaration of lin bus diagnostic.
*/
/*----------------------------------------------------------------------------*/
/**
*   \ingroup      doc_lin_main 
*   \addtogroup   doc_lin_diag LIN DB Diagnostic
*   \{
*   \brief      Diagnostic functions of LIN
*   \details    
*    
*   \internal
*   \endinternal
*
*/
/*----------------------------------------------------------------------------*/


// --------------------------------------------------------------------------------
// Function Switches
// --------------------------------------------------------------------------------

// set to TRUE if slave diagnosis is required
// and adapt parts that are node specific (like product id array etc.)
#define SLAVE_DIAGNOSTICS_ENABLED		FALSE



// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------

#include "lin_stack.h"

// --------------------------------------------------------------------------------
// LIN diagnose defines
// --------------------------------------------------------------------------------
#define NEGATIVE_RESPONSE_LEN       0x03u
#define NEGATIVE_RESPONSE_SID       0x7Fu
#define DIAG_RESP_DATA_BUFFER_SIZE  0x05u

#define ASSIGN_NAD_SID                  0xB0u
#define ASSIGN_FRAME_IDENTIFIER_SID     0xB1u
#define READ_BY_DATA_IDENTIFIER_SID     0xB2u
#define WRITE_BY_DATA_IDENTIFIER_SID    0x2Eu   // --> only for MRS write serial number

#define NRC_SERVICE_NOT_SUPPORTED  		0x11u
#define NRC_SUB_FUNCTION_NOT_SUPPORTED  0x12u

#define LIN_INITIAL_NAD 			0x01u

#define LIN_WILD_CARD_ID   			0x7Fu
#define LIN_SUPPLIER_ID_WILD_CARD   0x7FFFu
#define LIN_FUNCTION_ID_WILD_CARD   0xFFFFu

#define DID_LIN_PRODUCT_ID 			0x00u
#define DID_SERIAL_NUMBER 			0x01u

typedef enum
{
	LIN_DIAG_PAYLOAD_0 = 3,
	LIN_DIAG_PAYLOAD_1 = 4,
	LIN_DIAG_PAYLOAD_2 = 5,
	LIN_DIAG_PAYLOAD_3 = 6,
	LIN_DIAG_PAYLOAD_4 = 7
}ENUM_LIN_DIAG_POS_RESPONSE;


typedef enum
{
	PROD_ID_SUPPLIER_ID_LSB = 0,
	PROD_ID_SUPPLIER_ID_MSB = 1,
	PROD_ID_FUNCTION_ID_LSB = 2,
	PROD_ID_FUNCTION_ID_MSB = 3,
	PROD_ID_VARIANTID 		= 4
}ENUM_LIN_DIAG_PRODUCT_ID_INDEX;


typedef struct
{
	uint16_t supplier_id;
	uint16_t function_id;
	uint16_t variant_id;
}struct_LIN_DIAG_PROD_ID, *ptr_struct_LIN_DIAG_PROD_ID;

/*----------------------------------------------------------------------------*/
/** 
* \brief    LIN diagnose slave request frame received
* \details  
*           
*           
* \param    lin_module  [in] uint8_t    LIN index number --> enum_lin_bus_id
* \return   void      
*/
void lin_diag_master_request(uint8_t lin_module);

/*----------------------------------------------------------------------------*/
/** 
* \brief    LIN diagnose slave response frame header received,to prepare the response data.
* \details  
*           
*           
* \param    lin_module  [in] uint8_t    LIN index number --> enum_lin_bus_id
* \return   uint8_t                     LIN slave response result \n
*                                       LIN_STATE_SUCCESS --> response data OK send response \n
*                                       LIN_STATE_ERROR --> response data wrong send no response
*/
uint8_t lin_diag_slave_response(uint8_t lin_module);







/** \}*/
#endif




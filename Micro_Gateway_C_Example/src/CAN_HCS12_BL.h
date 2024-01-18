#ifndef CAN_FLASH_PROG_H
#define CAN_FLASH_PROG_H



#include "can_db.h"
#include "version_lib.h"



#define OS_1000ms                                   4       


#define PORTBYTE_HW_Bootloader                      0xFF00  
#define STATUS_OK                                   0xFF00  
#define STATUS_MRS_STOP_PROG                        0xFC03  
#define STATUS_WERK_STOP_PROG                       0xFB04  
#define STATUS_STOP_PROG                            0xFD02  
#define STATUS_STOP_PROG_und_FLASHER                0xFE01  

#define SUB_ID_BL_Adresse                           0x0     
#define SUB_ID_PC_Befehl                            0x1     
#define SUB_ID_BL_Antwort                           0x2     
#define SUB_ID_BL_Flashquittierung                  0x2     
#define SUB_ID_PC_Flashdaten                        0x3     
#define SUB_ID_BL_EEPromdaten                       0x4     
#define SUB_ID_PC_EEPromdaten                       0x5     
#define SUB_ID_PC_MAX_SUB                           0x5UL   




#define USER_BOOTLOADER_PARAMETER_Key_Empfangen     1       
#define USER_PARAMETER_Key_Empfangen                2       
#define USER_DATEN_Key_Empfangen                    3       


#define STARTKENNER                                 1331    

#define EEPROM_Adresse_Startkenner                  ((uint32_t) 2) 
#define EEPROM_LEN_Startkenner                      (uint32_t) 2  

#define EEPROM_Adresse_Seriennummer                 (EEPROM_Adresse_Startkenner + EEPROM_LEN_Startkenner)   
#define EEPROM_LEN_Seriennummer                     4 

#define EEPROM_Adresse_Teilenummer                  (EEPROM_Adresse_Seriennummer + EEPROM_LEN_Seriennummer)
#define EEPROM_LEN_Teilenummer                      12 

#define EEPROM_Adresse_Zeichnungsnummer             (EEPROM_Adresse_Teilenummer + EEPROM_LEN_Teilenummer)   
#define EEPROM_LEN_Zeichnungsnummer                 12  

#define EEPROM_Adresse_Bezeichnung                  (EEPROM_Adresse_Zeichnungsnummer + EEPROM_LEN_Zeichnungsnummer) 
#define EEPROM_LEN_Bezeichnung                      20  

#define EEPROM_Adresse_Fertigungsauftrag            (EEPROM_Adresse_Bezeichnung + EEPROM_LEN_Bezeichnung)  
#define EEPROM_LEN_Fertigungsauftrag                8  

#define EEPROM_Adresse_Pruefdatum                   (EEPROM_Adresse_Fertigungsauftrag + EEPROM_LEN_Fertigungsauftrag) 
#define EEPROM_LEN_Pruefdatum                       8  

#define EEPROM_Adresse_HW_Version                   (EEPROM_Adresse_Pruefdatum + EEPROM_LEN_Pruefdatum) 
#define EEPROM_LEN_HW_Version                       2  

#define EEPROM_Adresse_ResetCounter                 (EEPROM_Adresse_HW_Version + EEPROM_LEN_HW_Version) 
#define EEPROM_LEN_ResetCounter                     1 

#define EEPROM_Adresse_MRS_StudioVersion            (EEPROM_Adresse_ResetCounter + EEPROM_LEN_ResetCounter) 
#define EEPROM_LEN_MRS_StudioVersion                2  

#define EEPROM_Adresse_ResetReasonCounter           (EEPROM_Adresse_MRS_StudioVersion + EEPROM_LEN_MRS_StudioVersion) 
#define EEPROM_LEN_ResetReasonCounter               5 

#define EEPROM_Adresse_MCU_Type                     (EEPROM_Adresse_ResetReasonCounter + EEPROM_LEN_ResetReasonCounter)  
#define EEPROM_LEN_MCU_Type                         1 

#define EEPROM_Adresse_HW_CAN_Active                (EEPROM_Adresse_MCU_Type + EEPROM_LEN_MCU_Type) 
#define EEPROM_LEN_HW_CAN_Active                    1 

#define EEPROM_Adresse_Werksdaten_Reserve1          (EEPROM_Adresse_HW_CAN_Active + EEPROM_LEN_HW_CAN_Active)  
#define EEPROM_LEN_Bootloader_Werksdaten_Reserve1   3  

#define  EEPROM_Adresse_ENDE_Werksdaten             (EEPROM_Adresse_Werksdaten_Reserve1 + EEPROM_LEN_Bootloader_Werksdaten_Reserve1)  

#define EEPROM_Adresse_Bootloader_Version           EEPROM_Adresse_ENDE_Werksdaten  
#define EEPROM_LEN_Bootloader_Version               2  

#define EEPROM_Adresse_PROG_Status                  (EEPROM_Adresse_Bootloader_Version + EEPROM_LEN_Bootloader_Version)  
#define EEPROM_LEN_PROG_Status                      2  

#define EEPROM_Adresse_Portbyte1                    (EEPROM_Adresse_PROG_Status + EEPROM_LEN_PROG_Status )  
#define EEPROM_LEN_Portbyte1                        2  

#define EEPROM_Adresse_Portbyte2                    (EEPROM_Adresse_Portbyte1 + EEPROM_LEN_Portbyte1 )  
#define EEPROM_LEN_Portbyte2                        2  

#define EEPROM_Adresse_Baudrate_Bootloader1         (EEPROM_Adresse_Portbyte2 + EEPROM_LEN_Portbyte2 )   
#define EEPROM_LEN_Baudrate_Bootloader1             2  

#define EEPROM_Adresse_Baudrate_Bootloader2         (EEPROM_Adresse_Baudrate_Bootloader1 + EEPROM_LEN_Baudrate_Bootloader1 )  
#define EEPROM_LEN_Baudrate_Bootloader2             2  


#define EEPROM_Adresse_Bootloader_ID_ext            (EEPROM_Adresse_Baudrate_Bootloader2 + EEPROM_LEN_Baudrate_Bootloader2 )  
#define EEPROM_LEN_Bootloader_ID_ext                1  

#define EEPROM_Adresse_Bootloader_ID                (EEPROM_Adresse_Bootloader_ID_ext + EEPROM_LEN_Bootloader_ID_ext )   
#define EEPROM_LEN_Bootloader_ID                    4  

#define EEPROM_Adresse_Bootloader_ID_CRC            (EEPROM_Adresse_Bootloader_ID + EEPROM_LEN_Bootloader_ID ) 
#define EEPROM_LEN_Bootloader_ID_CRC                1  

#define EEPROM_Adresse_Bootloader_ID_Kopie_ext      (EEPROM_Adresse_Bootloader_ID_CRC + EEPROM_LEN_Bootloader_ID_CRC )  
#define EEPROM_LEN_Bootloader_ID_Kopie_ext          1  

#define EEPROM_Adresse_Bootloader_ID_Kopie          (EEPROM_Adresse_Bootloader_ID_Kopie_ext + EEPROM_LEN_Bootloader_ID_Kopie_ext)  
#define EEPROM_LEN_Bootloader_ID_Kopie              4  

#define EEPROM_Adresse_Bootloader_ID_Kopie_CRC      (EEPROM_Adresse_Bootloader_ID_Kopie + EEPROM_LEN_Bootloader_ID_Kopie )  
#define EEPROM_LEN_Bootloader_ID_Kopie_CRC          1  

#define EEPROM_Adresse_SW_Version                   (EEPROM_Adresse_Bootloader_ID_Kopie_CRC + EEPROM_LEN_Bootloader_ID_Kopie_CRC) 
#define EEPROM_LEN_SW_Version                       20  

#define EEPROM_Adresse_Modulname                    (EEPROM_Adresse_SW_Version + EEPROM_LEN_SW_Version) 
#define EEPROM_LEN_Modulname                        30  

#define EEPROM_Adresse_BL_CAN_Bus                   (EEPROM_Adresse_Modulname + EEPROM_LEN_Modulname) 
#define EEPROM_LEN_BL_CAN_Bus                       1  

#define EEPROM_Adresse_COP_WD_Timeout               (EEPROM_Adresse_BL_CAN_Bus + EEPROM_LEN_BL_CAN_Bus) 
#define EEPROM_LEN_COP_WD_Timeout                   2  

#define EEPROM_Adresse_Configdaten_Reserve1         (EEPROM_Adresse_COP_WD_Timeout + EEPROM_LEN_COP_WD_Timeout) 
#define EEPROM_LEN_Bootloader_Configdaten_Reserve1  7  

#define EEPROM_Adresse_CONFIG_ENDE                  (EEPROM_Adresse_Configdaten_Reserve1 + EEPROM_LEN_Bootloader_Configdaten_Reserve1)  


#define HSDDATENSATZ_SIZE                           48      
#define EEPROM_Adresse_START_HSDDATEN               0xC8U   
#define EEPROM_Adresse_LEN_HSDDATEN                 (HSDDATENSATZ_SIZE*2)   
#define EEPROM_HSD                                  0   
#define EEPROM_HSD_KENNER                           1   
#define EEPROM_USER                                 2   

#define EEPROM_Adresse_START_USERPARAMETER          EEPROM_Adresse_START_HSDDATEN   
#define EEPROM_Adresse_ENDE_USERPARAMETER           0x1FFU  

#define EEPROM_Adresse_START_USERDATEN              0x200U                 
#define EEPROM_Adresse_ENDE_USERDATEN               0x400U                 
#define EEPROM_Adresse_LEN_USERDATEN                (USERDATENSATZ_SIZE*2) 
#define EEPROM_Adresse_START_PROG_USERDATEN         0x401U                 
#define EEPROM_Adresse_ENDE_PROG_USERDATEN          0x500U                 


#define HCS12_MAX_TAB_SECTOR                        10

#define MCU_TYPE_FLASHER        2   




typedef struct
{
    uint32_t IdType;    
    uint32_t  Id;       
    uint8_t  Dlc;       
    uint8_t  Data[8];   
} canmsg_typ;


typedef struct 
{
     byte  size;                    
     dword realAddress;             
     byte  emptyVal;                
} tFlashInfo;


const    tFlashInfo flashtab1[];    


extern void __near (* __near Jump_To_Resetvector)(void);

void update_EEprom_SW_Version(void);  

uint8 bios_test_baudrate(uint8 bitrate);

void CAN1_INPUT_verarbeiten(void); 

void CAN2_INPUT_verarbeiten(void);

uint32_t Start_wait(uint32_t y);

extern void save_ReceiveCan1MsgBuffer(bios_can_msg_typ *ResiveMsg);



uint8_t Check_CRC(char *Datensatz, char Startpos , char anz_Bytes, uint8_t *Returnwert_CRC);


extern uint8_t Check_Portbyte (uint16_t Portbyte);


void HW_WATCHDOG_ON_OFF(void); 


void check_scan_delay(void);







extern void update_EEprom_Modulname(void);  
extern void read_EEPROM_MULTI_INFO(void) ;   
extern void sendeCan1Message(uint8_t Wait_Tx, uint32_t Id, uint8_t IdType,  uint8_t Dlc, uint8_t Byte0 , uint8_t Byte1 , uint8_t Byte2 , uint8_t Byte3 , uint8_t Byte4 , uint8_t Byte5 , uint8_t Byte6 , uint8_t Byte7 ); 
extern void sendeCan2Message(uint8_t Wait_Tx, uint32_t Id, uint8_t IdType,  uint8_t Dlc, uint8_t Byte0 , uint8_t Byte1 , uint8_t Byte2 , uint8_t Byte3 , uint8_t Byte4 , uint8_t Byte5 , uint8_t Byte6 , uint8_t Byte7 );
extern void reset_watchdog(void); 
extern void save_ReceiveCan2MsgBuffer(void);










extern uint8            hw_bootloader_access_en_aktiv;
extern uint8            hw_bootloader_access_en;
extern uint8            akt_Zustand_hw_bootloader_access_en;

extern unsigned long    TIMEROUT_ModulCanZugriff_aktiv;
extern uint8            HW_Bootloader_aktiv;
extern uint8            MRS_Produktion_Zugriff_aktiv; 
extern uint8            MRS_Produktion_aktiv;
extern uint8            ModulCanZugriff_aktiv;
extern uint8            USER_EEpromdaten_aktiv;

extern byte             EEPROM_Werksdaten_vorhanden;
extern unsigned long    EEPROM_Seriennummer;
extern unsigned int     EEPROM_Startkenner;
extern byte             EEPROM_ResetCounter;  
extern unsigned int     EEPROM_PROG_Status;  

extern unsigned int     EEPROM_HW_Version;
extern unsigned int     EEPROM_Bootloader_Version;
extern byte             EEPROM_Bootloader_ID_ext;
extern unsigned long    EEPROM_Bootloader_ID;
extern unsigned long    EEPROM_Bootloader_MAX_ID;
extern unsigned int     EEPROM_Bootloader_ID_NIBBLE;
extern byte             EEPROM_Bootloader_ID_CRC;
extern byte             EEPROM_Bootloader_ID_Kopie_ext;
extern unsigned long    EEPROM_Bootloader_ID_Kopie;
extern unsigned int     EEPROM_Bootloader_ID_Kopie_NIBBLE;
extern byte             EEPROM_Bootloader_ID_Kopie_CRC;

extern unsigned int     EEPROM_Baudrate_Bootloader1;
extern unsigned int     EEPROM_Baudrate_Bootloader2;
extern unsigned int     EEPROM_Portbyte1;
extern unsigned int     EEPROM_Portbyte2;
extern unsigned int     EEPROM_MRS_StudioVersion;

extern char             EEPROM_Modulname[];
extern char             EEPROM_SW_Version[];          
extern char             EEPROM_Bezeichnung[];          
extern uint8            USER_EEpromdaten_aktiv;
extern char             EEPROM_SW_Version[EEPROM_LEN_SW_Version+1];
extern char             EEPROM_Modulname[EEPROM_LEN_Modulname+1];

extern uint8_t          Flashdatensatz[];

extern byte             ResetReason;
extern const uint8_t    BOOTLOADER_VERSION;


extern unsigned long    EEPROM_Seriennummer;
extern byte             EEPROM_Bootloader_ID_ext ;
extern unsigned int     EEPROM_PROG_Status ;  
extern byte             EEPROM_ResetCounter ;  
extern unsigned long    EEPROM_Bootloader_ID;
extern unsigned long    EEPROM_Bootloader_MAX_ID;
extern unsigned int     EEPROM_Startkenner;
extern unsigned int     EEPROM_HW_Version;
extern unsigned int     EEPROM_Bootloader_Version;
extern unsigned int     EEPROM_Bootloader_ID_NIBBLE;
extern byte             EEPROM_Bootloader_ID_CRC;
extern unsigned int     EEPROM_Baudrate_Bootloader1;
extern unsigned int     EEPROM_MRS_StudioVersion ;
extern byte             EEPROM_MCU_Type;
extern byte             EEPROM_BL_CAN_Bus;
extern byte             EEPROM_HW_CAN_Active;
extern uint32           user_variable[];
extern uint16           eeprom_hsddaten[];
extern uint16           eeprom_hsddaten_type;
extern uint16           eeprom_userdaten[];

extern unsigned long    TIMEROUT_ModulCanZugriff_aktiv ;
extern  uint8_t         HW_Bootloader_aktiv;
extern uint8_t          MRS_Produktion_Zugriff_aktiv ; 
extern uint8_t          MRS_Produktion_aktiv ;
extern uint8_t          USER_EEpromdaten_aktiv;
extern uint8_t          ModulCanZugriff_aktiv;

extern uint8            hw_bootloader_access_en ;                                       
extern uint8            akt_Zustand_hw_bootloader_access_en ;               
extern uint8            hw_bootloader_access_en_aktiv ;         

extern uint8            modulename_change;

extern uint32_t         ProgAdressse;  




#endif



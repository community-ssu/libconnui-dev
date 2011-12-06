/**
 * @file net_definition.h
 *
 *  This file contains all definitions needed by client so that it can use 
 *  services offered by Phone.Net.
 *
 *  @author Jukka Paakkunainen <jukka.paakkunainen@nokia.com>
 *
 *  Coryright (C) 2007-2008 Nokia Corporation
*/

#ifndef NET_DEFINITIONS_H
#define NET_DEFINITIONS_H

#include "general_definitions.h" // for general definitions that need to send 
                                 // for client
#include <sys/types.h>       // for general types
#include <stddef.h>          // for general definitions

#define NETWORK_INVALID_TIME        0x64

// Daylight saving time
#define NETWORK_DST_INFO_NOT_AVAIL  0x64    // Information not available
#define NETWORK_DST_1_HOUR          0x01    // Local time zone adjusted by 1 hour
#define NETWORK_DST_2_HOURS         0x02    // Local time zone adjusted by 2 hours
#define NETWORK_DST_0_HOUR          0x00    // No adjustment to local time zone

// Mask bits for supported services in net_get_reg_status_resp
#define NETWORK_MASK_GPRS_SUPPORT   0x01
#define NETWORK_MASK_CS_SERVICES    0x02
#define NETWORK_MASK_EGPRS_SUPPORT  0x04
#define NETWORK_MASK_HSDPA_AVAIL    0x08
#define NETWORK_MASK_HSUPA_AVAIL    0x10

#define NETWORK_DISPLAY_TAG_LENGTH  40
#define NETWORK_LONG_NAME_LENGTH    20
#define NETWORK_SHORT_NAME_LENGTH   10

// Network selection mode is unset or does not matter
#define NETWORK_SELECT_MODE_UNKNOWN       0x00

// Network selection mode is manual
#define NETWORK_SELECT_MODE_MANUAL        0x01

// Network selection mode is automatic 
#define NETWORK_SELECT_MODE_AUTOMATIC     0x02

// CS performs user reselection. This is currently GSM-specific procedure, which is
// specified in GSM TS 03.22.
#define NETWORK_SELECT_MODE_NO_SELECTION  0x04 

// Network status availability of operators
#define NETWORK_OPER_STATUS_UNKNOWN       0x00  // It is not known in which category operator belongs
#define NETWORK_OPER_STATUS_AVAILABLE     0x01  // The operator is heard and allowed
#define NETWORK_OPER_STATUS_CURRENT       0x02  // The CS is currently in service in this operator
#define NETWORK_OPER_STATUS_FORBIDDEN     0x03  // The operator is forbidden

// network get cell info: cell type 
#define NETWORK_UNKNOWN_CELL        0
#define NETWORK_GSM_CELL            1
#define NETWORK_WCDMA_CELL          2

// Cellular system states
#define NETWORK_CS_INACTIVE         0x00
#define NETWORK_CS_ACTIVE           0x01
#define NETWORK_CS_STATE_UNKNOWN    0x02

// Cellular system operation modes
#define NETWORK_CS_OP_MODE_NORMAL    0x00   // CS is in normal operation mode
#define NETWORK_CS_OP_MODE_GAN_ONLY  0x01   // CS is in GAN only operation mode
#define NETWORK_CS_OP_MODE_UNKNOWN   0x02

// Cellular system service status
#define NETWORK_CS_IN_SERVICE           0X00
#define NETWORK_CS_IN_LIMITED_SERVICE   0X01
#define NETWORK_CS_NO_COVERAGE          0X02 // CS is not in service. Other cell informations are not valid

// Cellular system types
#define NETWORK_CS_GSM               0x00
#define NETWORK_CS_TYPE_UNKNOWN      0x01

// UMTS availability
#define NETWORK_UMTS_NOT_AVAILABLE   0X00
#define NETWORK_UMTS_AVAILABLE       0X01

// Radio access technology names
#define NETWORK_RAT_NAME_UNKNOWN         0x00
#define NETWORK_GSM_RAT                  0x01
#define NETWORK_UMTS_RAT                 0x02

// Selected rat type
#define NET_GSS_DUAL_SELECTED_RAT            0x00
#define NET_GSS_GSM_SELECTED_RAT             0x01
#define NET_GSS_UMTS_SELECTED_RAT            0x02
#define NET_GSS_UNKNOWN_SELECTED_RAT         0x03

// Cellular system control message types
#define NETWORK_CS_POWER_UNKNOWN             0x00 // means that band resume is requested
#define NETWORK_CS_POWER_OFF                 0x02 // means that CS shall be switched off, it is possible that this causes deregistration to network
#define NETWORK_CS_POWER_ON                  0x03 // means that CS shall be switched on
#define NETWORK_CS_POWER_WIFI                0x05 // means that CS shall be switched to GAN flight mode

// UTARN radio states
#define NETWORK_UTRAN_RADIO_IDLE             0x00 // Radio state is Idle
#define NETWORK_UTRAN_RADIO_CELL_DCH         0x01 // Radio state is Cell DCH


// Enum for describing net specific errors
enum net_error {
    NETWORK_ERROR_COMMUNICATION_ERROR = SPECIFIC_ERROR_START,
    NETWORK_ERROR_INVALID_PARAMETER,
    NETWORK_ERROR_NO_SIM,
    NETWORK_ERROR_SIM_NOT_YET_READY,                                                    
    NETWORK_ERROR_NET_NOT_FOUND,                                                    
    NETWORK_ERROR_REQUEST_NOT_ALLOWED,                                                    
    NETWORK_ERROR_CALL_ACTIVE,                                                    
    NETWORK_ERROR_SERVER_BUSY,                                                    
    NETWORK_ERROR_SECURITY_CODE_REQUIRED,                                                    
    NETWORK_ERROR_NOTHING_TO_CANCEL,                                                    
    NETWORK_ERROR_UNABLE_TO_CANCEL,                                                    
    NETWORK_ERROR_NETWORK_FORBIDDEN,                                                    
    NETWORK_ERROR_REQUEST_REJECTED,                                                    
    NETWORK_ERROR_CS_NOT_SUPPORTED,                                                    
    NETWORK_ERROR_PAR_INFO_NOT_AVAILABLE,                                                    
    NETWORK_ERROR_NOT_DONE,                                                
    NETWORK_ERROR_NO_SELECTED_NETWORK,                                                
    NETWORK_ERROR_REQUEST_INTERRUPTED,                                                
    NETWORK_ERROR_TOO_BIG_INDEX,                                                
    NETWORK_ERROR_MEMORY_FULL,                                                
    NETWORK_ERROR_SERVICE_NOT_ALLOWED,                                                
    NETWORK_ERROR_NOT_SUPPORTED_IN_TECH,
    NETWORK_ERROR_UNKNOWN
};

// Enum for describing net gsm specific reject codes
enum net_reject_codes {
    NETWORK_GSM_UNKNOWN_REJECT_CODE = 0x00,
    NETWORK_GSM_IMSI_UNKNOWN_IN_HLR = 0x02,
    NETWORK_GSM_ILLEGAL_MS,
    NETWORK_GSM_IMSI_UNKNOWN_IN_VLR,
    NETWORK_GSM_IMEI_NOT_ACCEPTED,
    NETWORK_GSM_ILLEGAL_ME,
    NETWORK_GSM_GPRS_SERVICES_NOT_ALLOWED,
    NETWORK_GSM_GPRS_AND_NON_GPRS_NA,
    NETWORK_GSM_MS_ID_CANNOT_BE_DERIVED,
    NETWORK_GSM_IMPLICITLY_DETACHED,
    NETWORK_GSM_PLMN_NOT_ALLOWED,
    NETWORK_GSM_LA_NOT_ALLOWED,
    NETWORK_GSM_ROAMING_NOT_IN_THIS_LA,
    NETWORK_GSM_GPRS_SERV_NA_IN_THIS_PLMN,
    NETWORK_GSM_NO_SUITABLE_CELLS_IN_LA,
    NETWORK_GSM_MSC_TEMP_NOT_REACHABLE,
    NETWORK_GSM_NETWORK_FAILURE,
    NETWORK_GSM_MAC_FAILURE,
    NETWORK_GSM_SYNCH_FAILURE,
    NETWORK_GSM_CONGESTION,
    NETWORK_GSM_AUTH_UNACCEPTABLE,
    NETWORK_GSM_SERV_OPT_NOT_SUPPORTED = 0x20,
    NETWORK_GSM_SERV_OPT_NOT_SUBSCRIBED,
    NETWORK_GSM_SERV_TEMP_OUT_OF_ORDER,
    NETWORK_GSM_RETRY_ENTRY_NEW_CELL_LOW = 0x30,
    NETWORK_GSM_RETRY_ENTRY_NEW_CELL_HIGH = 0x3F,
    NETWORK_GSM_SEMANTICALLY_INCORRECT = 0x5F,
    NETWORK_GSM_INVALID_MANDATORY_INFO = 0x60,
    NETWORK_GSM_MSG_TYPE_NONEXISTENT,
    NETWORK_GSM_CONDITIONAL_IE_ERROR = 0x64,
    NETWORK_GSM_MSG_TYPE_WRONG_STATE,
    NETWORK_GSM_PROTOCOL_ERROR_UNSPECIFIED = 0x6F
};                                                

// Enum for describing gss specific errors
enum gss_error {
    NET_GSS_ERROR_OK = 0x00,                                                    
    NET_GSS_ERROR_SERVICE_FAIL = SPECIFIC_ERROR_START,
    NET_GSS_ERROR_SERVICE_NOT_ALLOWED,
    NET_GSS_ERROR_SERVICE_FAIL_CS_INACTIVE,
    NET_GSS_ERROR_UNKNOWN
};

enum net_registration_status
{
    NETWORK_REG_STATUS_HOME = 0x00, // CS is registered to home network
    NETWORK_REG_STATUS_ROAM,        // CS is registered to some other network than home network
    NETWORK_REG_STATUS_ROAM_BLINK,  // CS is registered to non-home system in a non-home area ('a' or 'b' area)
    NETWORK_REG_STATUS_NOSERV,      // CS is not in service
    NETWORK_REG_STATUS_NOSERV_SEARCHING,    // CS is not in service, but is currently searching for service
    NETWORK_REG_STATUS_NOSERV_NOTSEARCHING, // CS is not in service and it is not currently searching for service
    NETWORK_REG_STATUS_NOSERV_NOSIM,        // CS is not in service due to missing SIM or missing subscription
    NETWORK_REG_STATUS_POWER_OFF = 0x08,    // CS is in power off state
    NETWORK_REG_STATUS_NSPS,                // CS is in No Service Power Save State (currently not listening to any cell)
    NETWORK_REG_STATUS_NSPS_NO_COVERAGE,    // CS is in No Service Power Save State (CS is entered to this state because there is no network coverage)
    NETWORK_REG_STATUS_NOSERV_SIM_REJECTED_BY_NW // CS is not in service due to missing subscription
};

enum network_mode 
{
    NETWORK_MODE_UNKNOWN = 0,
    NETWORK_MODE_GSM,
    NETWORK_MODE_UMTS
};

enum network_rat_type
{
    NETWORK_UNKNOWN_RAT,
    NETWORK_CURRENT_RAT,
    NETWORK_SUPPORTED_RATS
};

enum network_alpha_tag_name_type
{
// The operator name contains only 'ordinary' characters. The operator name is
// from the hard-coded operator name list
    NETWORK_HARDCODED_LATIN_OPER_NAME = 0,
// The operator name contains some language specific characters (like Chinese).
// The operator name is from the hard-coded operator name list
    NETWORK_HARDCODED_USC2_OPER_NAME,
// The operator name is received from the cellular network in a special message 
// containing the operator name. The network has indicated that this name is a
// short name.
    NETWORK_NITZ_SHORT_OPER_NAME,
// The operator name is received from the cellular network in a special message
// containing the operator name. The network has indicated that this is a full
// name operator name.
    NETWORK_NITZ_FULL_OPER_NAME,
// The operator name from SIM card 
    NETWORK_SIM_OPER_NAME = 0x08,
// The operator name is received from the SIM and it is mapped to certain LAC. 
// The SIM has indicated that this name is a short name.  
    NETWORK_EONS_SHORT_OPER_NAME,
// The operator name is received from the SIM and it is mapped to certain LAC. 
// The SIM has indicated that this is a full name 
    NETWORK_EONS_FULL_OPER_NAME
};

enum network_band_info
{
    NETWORK_GSM_BAND_900_1800 = 0,
    NETWORK_GSM_BAND_850_1900,
    NETWORK_GSM_BAND_INFO_NOT_AVAIL,
    NETWORK_GSM_BAND_ALL_SUPPORTED_BANDS // All supported bands can be used
};

enum network_types
{
    NETWORK_GSM_HOME_PLMN = 0,  // GSM operator code equals to home network operator code
    NETWORK_GSM_PREFERRED_PLMN, // GSM operator code is same as one of the operator codes in PLMN selection list of SIM card
    NETWORK_GSM_FORBIDDEN_PLMN, // GSM operator code is same as one of the forbidden PLMN operator codes
    NETWORK_GSM_OTHER_PLMN,     // GSM operator code can not be identified as neither home PLMN nor preferred PLMN nor forbidden PLMN
    NETWORK_GSM_NO_PLMN_AVAIL   //  	There is no GSM operator available
};

enum network_gprs_modes
{
    NETWORK_GPRS_MODE_NONE = 0, // Mode is unknown or GPRS is not in use
    NETWORK_GPRS_MODE1,         // Combined location update procedure for GMM and MM is used
    NETWORK_GPRS_MODE2,         // Both GMM and MM perform a separate location update
    NETWORK_GPRS_MODE3          // Either GMM or MM is registered and performs the location update
};

#endif // NET_DEFINITIONS_H

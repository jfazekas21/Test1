/******************************************************************************
*				File:				quartz_comm_misc_structures.h								*
*  			Description:	Communications Misc Structure Definitions				*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_MISC_STRUCTURES_H
#define QUARTZ_COMM_MISC_STRUCTURES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_structures.h"					// Communications Base Structures
#include "quartz_comm_misc_defines.h"				// Communications Miscellaneous Defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


// *** ENU_CMD_MISC_HEARTBEAT - Heartbeat packets

typedef struct		misc_heartbeat_req_struct
{
    uint_8              command;						// misc command code [MISC_CMD_ENU]
    uint_8              option_code;				// heartbeat option code [HEARTBEAT_OPT_ENU]
    uint_8              year;
    uint_8              month;
    uint_8              day;
    uint_8              hour;
    uint_8              minute;
    uint_8              second;
    uint_16             msecond;
} MISC_HEARTBEAT_REQ_STR;

typedef struct		misc_heartbeat_ack_struct
{
    uint_8              		command;						// misc command code [MISC_CMD_ENU]
    uint_8              		major_ver;					// firmware major version			
    uint_8              		minor_ver;					// firmware minor version
    uint_8							reserved;
	 uint_32							purge_count;
	 TEST_MODULE_STATUS_ENU		module_status;				// test module status
	 uint_32							cop_version_number;		// cop version number
} MISC_HEARTBEAT_ACK_STR;


typedef struct		misc_board_test_req_struct  	// command is for asking for board test result
{
    uint_8              command;						// misc command code [MISC_CMD_ENU]
} MISC_BOARD_TEST_REQ_STR;

typedef struct		misc_board_test_ack_struct	
{
    uint_8              command;						// misc command code [MISC_CMD_ENU] 
    uint_8              result;						// result of board test [BOARD_TEST_RESULT_ENU]
} MISC_BOARD_TEST_ACK_STR;


typedef struct		misc_board_reset_req_struct  // command is for asking for test result info
{
    uint_8              command;						// misc command code [MISC_CMD_ENU]
	 uint_8 					validation_byte1;			// R - these must be set to reset the board
	 uint_8 					validation_byte2;			// E
	 uint_8 					validation_byte3;			// S
	 uint_8 					validation_byte4;			// E
  	 uint_8 					validation_byte5;			// T 
} MISC_BOARD_RESET_REQ_STR;


	// *** Communications Payload - File packets union
	typedef union	payload_misc_union							
	{
		uint_8								command;
		MISC_HEARTBEAT_REQ_STR			str_heartbeat_req;
		MISC_HEARTBEAT_ACK_STR			str_heartbeat_ack;
		MISC_BOARD_TEST_REQ_STR			str_board_test_req; 
		MISC_BOARD_TEST_ACK_STR			str_board_test_ack;
		MISC_BOARD_RESET_REQ_STR		str_board_reset_req;
	} PAYLOAD_MISC_UNI;


#endif // QUARTZ_COMM_MISC_STRUCTURES_H


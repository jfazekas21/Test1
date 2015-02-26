/******************************************************************************
*				File:				quartz_comm_misc_defines.h									*
*  			Description:	Communications Misc Definitions							*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_MISC_DEFINES_H
#define QUARTZ_COMM_MISC_DEFINES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_defines.h"						// Communications Base Defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/

typedef enum								// miscellaneous command codes
{
	ENU_CMD_MISC_UNDEF,						// undefined command code
	ENU_CMD_MISC_INVALID,					// interpreted data was invalid (error response)
	ENU_CMD_MISC_HEARTBEAT,					// heartbeat packet
	ENU_CMD_MISC_BOARD_TEST,				// board test packet
	ENU_CMD_MISC_BOARD_RESET,				// board reset packet
	ENU_CMD_MISC_MAX
} MISC_CMD_ENU;

typedef enum								// heartbeat option codes
{
	ENU_HEARTBEAT_OPT_UNDEF,				// undefined
	ENU_HEARTBEAT_OPT_SET_TIME,			// set system time and respond 
	ENU_HEARTBEAT_OPT_KEEP_ALIVE			// no response
} HEARTBEAT_OPT_ENU;

typedef enum								// board test result codes
{
	ENU_BOARD_TEST_RESULT_UNDEF,				// undefined
	ENU_BOARD_TEST_RESULT_NOT_RAN,				// undefined
	ENU_BOARD_TEST_RESULT_PASSED,				// undefined
	ENU_BOARD_TEST_RESULT_FAILED				// undefined
} BOARD_TEST_RESULT_ENU;


typedef enum
{
	ENU_TEST_MODULE_STATUS_UNDEF,					// undefined
	ENU_TEST_MODULE_STATUS_LOADING,				// System Not Ready - Loading (initial state)
	ENU_TEST_MODULE_STATUS_UPDATING_COP,		// System Not Ready - Updating co-processors
	ENU_TEST_MODULE_STATUS_READING_STORAGE,	// System Not Ready - Performing file storage maintenance (fixing corruption, upgrading files, etc)
	ENU_TEST_MODULE_STATUS_FAULT_COP,			// System Not Ready - COP error, unable to test
	ENU_TEST_MODULE_STATUS_FAULT_FILE,			// System Not Ready - File load error, currently running with default data set
	ENU_TEST_MODULE_STATUS_FAULT_UNDEF,			// System Not Ready - Undefined fault (any task load faults, aborts, fatal errors)
	ENU_TEST_MODULE_STATUS_READY,					// System Ready
	ENU_TEST_MODULE_STATUS_MAX						// undefined
} TEST_MODULE_STATUS_ENU;

/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


#endif // QUARTZ_COMM_MISC_DEFINES_H


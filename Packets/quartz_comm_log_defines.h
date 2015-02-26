/******************************************************************************
*				File:				quartz_comm_log_defines.h									*
*  			Description:	Communications Log Definitions							*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_LOG_DEFINES_H
#define QUARTZ_COMM_LOG_DEFINES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_defines.h"					// Communications Base Defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/

#define DEF_MAX_LOG_ASCII_SIZE					156		// maximum size of the formatted ASCII log entry
#define DEF_MAX_LOG_ELEMENTS						9			// maximum number of entries per log packet

/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/

typedef enum							// log command codes
{
	ENU_CMD_LOG_UNDEF,					// undefined command code
	ENU_CMD_LOG_INVALID,					// interpreted data was invalid (error response)
	ENU_CMD_LOG_DATA,						// log data packet
	ENU_CMD_LOG_MAX
} LOG_CMD_ENU;

/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


#endif // QUARTZ_COMM_LOG_DEFINES_H


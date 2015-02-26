/******************************************************************************
*				File:				quartz_comm_log_structures.h								*
*  			Description:	Communications Log Structure Definitions				*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_LOG_STRUCTURES_H
#define QUARTZ_COMM_LOG_STRUCTURES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_structures.h"					// Communications Base Structures
#include "quartz_comm_log_defines.h"				// Communications Log Defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


// *** ENU_CMD_LOG_DATA - Log packets - log data

typedef struct log_data_element_struct			// log string element structure
{
	uint_32	length; 										// length of log string
	uint_8	data[DEF_MAX_LOG_ASCII_SIZE];			// log ASCII string
} LOG_DATA_ELEMENT_STR;

   typedef struct log_data_struct					// log data structure 
   {
		uint_8 							command;				// log command code [LOG_CMD_ENU]
		uint_8							num_log_elements;	// number of log entries in packet
      LOG_DATA_ELEMENT_STR			element[DEF_MAX_LOG_ELEMENTS];
   } LOG_DATA_STR;
   
	#define LOG_DATA_SIZE(x) 		(offsetof(LOG_DATA_STR, element) + (x * sizeof(LOG_DATA_ELEMENT_STR)))


		// *** Communications Payload - System Log packets union
		typedef union	payload_log_union
		{
			uint_8								command;
			LOG_DATA_STR						str_log;
		} PAYLOAD_LOG_UNI;


#endif // QUARTZ_COMM_LOG_STRUCTURES_H


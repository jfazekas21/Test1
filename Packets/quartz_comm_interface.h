/******************************************************************************
*				File:				quartz_comm_interface.h										*
*  			Description:	Data search header file										*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_INTERFACE_H
#define QUARTZ_COMM_INTERFACE_H


#ifdef DEF_HMI
	#pragma pack(push,1)
#endif

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_test_structures.h"		// Communications Test Structures defines
#include "quartz_comm_data_structures.h"		// Communications Data Structures defines
#include "quartz_comm_misc_structures.h"		// Communications Miscellaneous Structures defines
#include "quartz_comm_file_structures.h"		// Communications File Structures defines
#include "quartz_comm_log_structures.h"		// Communications Log Structures defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/

#define DEF_COMM_INTERFACE_VERSION	1


/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/

typedef enum								// payload command codes
{
	ENU_CMD_PAYLOAD_UNDEF,					// undefined command code
	ENU_CMD_PAYLOAD_TEST,					// test operation packets		
	ENU_CMD_PAYLOAD_DATA,					// configuration data packets		
	ENU_CMD_PAYLOAD_MISC,					// miscellaneous (configuration, announcement, heartbeat) packets
	ENU_CMD_PAYLOAD_FILE,					// file data packets
	ENU_CMD_PAYLOAD_LOG,						// system log data packets
	ENU_CMD_PAYLOAD_MAX
} PAYLOAD_CMD_ENU;

typedef enum								// packet priority level
{
	ENU_PRIORITY_LEVEL_UNDEF,				// undefined priority level
	ENU_PRIORITY_LEVEL_1,					// priority level 1 (high priority traffic)
	ENU_PRIORITY_LEVEL_2,					// priority level 2 (medium priority traffic)
	ENU_PRIORITY_LEVEL_3,					// priority level 3 (low priority traffic)
	ENU_PRIORITY_LEVEL_4,					// priority level 4 (background priority traffic)
	ENU_PRIORITY_LEVEL_MAX
} PRIORITY_LEVEL_ENU;

/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


// *** Communications Payload Union
typedef union	payload_union						
{
	PAYLOAD_TEST_UNI			uni_test;			// test operation payload union
	PAYLOAD_DATA_UNI			uni_data;			// data payload union
	PAYLOAD_MISC_UNI			uni_misc;			// miscellaneous payload union
	PAYLOAD_FILE_UNI			uni_file;			// file payload union
	PAYLOAD_LOG_UNI			uni_log;				// log payload union
} PAYLOAD_UNI;	

	typedef struct	payload_command_struct						// payload command structure
	{
		uint_8						command;								// payload command code [PAYLOAD_CMD_ENU]
		uint_8						reserved_1;							// reserved byte (alignment)
		uint_8						reserved_2;							// reserved byte (alignment)
		uint_8						reserved_3;							// reserved byte (alignment)
		PAYLOAD_UNI					uni_payload;						// packet payload data
	} PAYLOAD_CMD_STR;
	
	#define PAYLOAD_CMD_HDR_SIZE		offsetof(PAYLOAD_CMD_STR, uni_payload)


		// *** Communications Top Level Packet Structure
		typedef struct	packet_data_struct							// packet data structure (with data content)
		{
			uint_32						interface;							// HMI interface identifier (not useful to TCM)
			uint_8						module_num;							// module number	
			uint_8						priority;							// priority level of the packet [PRIORITY_LEVEL_ENU]
			uint_8						packet_num;							// multi-packet handling number X, as in (X of Y)
			uint_8						packet_total;						// multi-packet handling total Y, as in (X of Y)
			uint_8						sequence;							// packet level tracking
			uint_8						control;								// packet level tracking
			uint_16						payload_bytes;						// number of bytes in packet payload
			PAYLOAD_CMD_STR			str_payload;						// packet payload
		} PACKET_STR;

		#define PACKET_HDR_SIZE		offsetof(PACKET_STR, str_payload)


#ifdef DEF_HMI
	#pragma pack(pop)
#endif

#endif // QUARTZ_COMM_INTERFACE_H


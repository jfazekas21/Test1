/******************************************************************************
*				File:				quartz_comm_file_structures.h								*
*  			Description:	Communications File Structure Definitions				*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_FILE_STRUCTURES_H
#define QUARTZ_COMM_FILE_STRUCTURES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_structures.h"					// Communications Base Structures
#include "quartz_comm_file_defines.h"				// Communications File Defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


// *** ENU_CMD_FILE_WRITE - File packets - write file request
            
typedef struct file_write_str								// file write structure
{
	uint_8	command;												// file command code [FILE_CMD_ENU]
	uint_8	mode;													// file mode code [FILE_MODE_ENU]
	uint_8	reserved_1;											// reserved byte (alignment)
	uint_8	file_version;										// version (0=newest)
	uint_8	file_id[DEF_MAX_FILE_NAME_SIZE];				// basename
	uint_32	file_length;										// overall file length
	uint_32	file_crc;											// crc
} FILE_WRITE_STR;


// *** ENU_CMD_FILE_READ - File packets - read file request

typedef struct file_read_str								// file read structure
{
	uint_8	command;												// file command code [FILE_CMD_ENU]
	uint_8	mode;													// file mode code [FILE_MODE_ENU]
	uint_8	reserved_1;											// reserved byte (alignment)
	uint_8	file_version;										// version (0=newest)
	uint_8	file_id[DEF_MAX_FILE_NAME_SIZE];				// basename
	uint_32	file_max_length;									// max file size
} FILE_READ_STR;


// *** ENU_CMD_FILE_DATA - File packets - file data transfer

typedef struct file_data_str								// file data contents structure
{
	uint_8	command;												// file command code [FILE_CMD_ENU]
	uint_8	mode;													// file mode code [FILE_MODE_ENU]
	uint_8	reserved_1;											// reserved byte (alignment)
	uint_8	file_version;										// version (0=newest)
	uint_8	file_id[DEF_MAX_FILE_NAME_SIZE];				// basename
	uint_32	file_length;										// overall file length
	uint_32	pkt_offset;											// starting offset of first data byte in this packet
	uint_32	pkt_length;											// number of bytes of data in this packet
	uint_8	pkt_data[DEF_MAX_FILE_DATA_SIZE];
} FILE_DATA_STR;

#define FILE_DATA_HDR_SIZE		offsetof(FILE_DATA_STR, pkt_data)


// *** ENU_CMD_FILE_DELETE - File packets - file delete request

typedef struct file_delete_str							// file delete structure
{
	uint_8	command;												// file command code [FILE_CMD_ENU]
	uint_8	mode;													// file mode [FILE_MODE_ENU]
	uint_8	reserved_1;											// reserved byte (alignment)
	uint_8	file_version;										// version (0=newest)
	uint_8	file_id[DEF_MAX_FILE_NAME_SIZE];		// basename
} FILE_DELETE_STR;


// *** ENU_CMD_FILE_RESPONSE - File packets - file response packets

typedef struct file_response_str							// file response structure
{		
	uint_8	command;												// file command code [FILE_CMD_ENU]
	uint_8	response_code;										// response code [FILE_RSP_ENU]
	uint_8	file_version;										// version (0=newest)
	uint_8	reserved_1;											// reserved byte (alignment)	
	uint_8	file_id[DEF_MAX_FILE_NAME_SIZE];				// matches file_id from command msg
	uint_8	file_name_out[DEF_MAX_FILE_NAME_SIZE];		// filename out
	uint_32	rsp_parm;
} FILE_RESPONSE_STR;


	// *** Communications Payload - File packets union
	typedef union	payload_file_union
	{
		uint_8								command;
		FILE_WRITE_STR						str_file_write;
		FILE_READ_STR						str_file_read;
		FILE_DATA_STR						str_file_data;
		FILE_DELETE_STR					str_file_delete;
		FILE_RESPONSE_STR					str_file_response;
	} PAYLOAD_FILE_UNI;


#endif // QUARTZ_COMM_FILE_STRUCTURES_H


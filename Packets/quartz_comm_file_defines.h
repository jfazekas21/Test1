/******************************************************************************
*				File:				quartz_comm_file_defines.h									*
*  			Description:	Communications File Definitions							*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_FILE_DEFINES_H
#define QUARTZ_COMM_FILE_DEFINES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_defines.h"						// Communications Base Defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/

#define DEF_MAX_FILE_DATA_SIZE				1372		// 1500-(UdpHeaderSize+PACKET_HDR_SIZE+PAYLOAD_CMD_HDR_SIZE+FILE_DATA_HDR_SIZE)
#define DEF_MAX_FILE_NAME_SIZE				64

/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/

typedef enum									// file command codes
{
	ENU_CMD_FILE_UNDEF,						// undefined command code
	ENU_CMD_FILE_INVALID,					// interpreted data was invalid (error response)
	ENU_CMD_FILE_WRITE,
	ENU_CMD_FILE_READ,
	ENU_CMD_FILE_DATA,
	ENU_CMD_FILE_DELETE,
	ENU_CMD_FILE_RESPONSE,
	ENU_CMD_FILE_MAX
} FILE_CMD_ENU;

typedef enum									// file mode codes
{
	ENU_FILE_MODE_UNDEF,
	ENU_FILE_MODE_WR_EXIST,
	ENU_FILE_MODE_WR_CREATE,
	ENU_FILE_MODE_WR_EXIST_CREATE,
	ENU_FILE_MODE_WR_EXIST_FORCE_COMMIT,
	ENU_FILE_MODE_WR_CREATE_FORCE_COMMIT,
	ENU_FILE_MODE_WR_EXIST_CREATE_FORCE_COMMIT,
	ENU_FILE_MODE_WR_DATA,
	ENU_FILE_MODE_WR_CLOSE,
	ENU_FILE_MODE_WR_CLOSE_AND_COMMIT,
	ENU_FILE_MODE_RD_BASENAME_LIVE,
	ENU_FILE_MODE_RD_BASENAME_MIRROR,
	ENU_FILE_MODE_RD_FILENAME_LIVE,
	ENU_FILE_MODE_RD_FILENAME_MIRROR,
   ENU_FILE_MODE_RD_BASENAME_LIST,				// retrieves list of basenames with number of versions in each
	ENU_FILE_MODE_RD_BASENAME_VERSIONS,			// returns number of version in specified basename
	ENU_FILE_MODE_RD_DATA,
	ENU_FILE_MODE_RD_CLOSE,
	ENU_FILE_MODE_DELETE_VERSION,					// deletes specific version of basename
	ENU_FILE_MODE_DELETE_KEY,						// deletes a file by name
	ENU_FILE_MODE_DELETE_BASENAME,				// deletes basename
	ENU_FILE_MODE_DELETE_BASENAME_PURGE,		// purges basename to spcified number of versions
	ENU_FILE_MODE_DELETE_DATABASE_PURGE,		// purges all basenames to spcified number of versions
	ENU_FILE_MODE_MAX
} FILE_MODE_ENU;

typedef enum									// file response codes
{
    ENU_FILE_RSP_SUCCESS = 0,
    ENU_FILE_RSP_ERROR,
    // error codes from HMI/RawStorage
    ENU_FILE_RSP_INVALID_MODE,                          // invalid mode request for current RawStorage state
    ENU_FILE_RSP_UNKNOWN_MODE,                          // mode request not valid for command
    ENU_FILE_RSP_INVALID_LENGTH,                        // requested file length too large for RawStorage
    ENU_FILE_RSP_BASENAME_DOES_NOT_EXIST,
    ENU_FILE_RSP_BASENAME_ALREADY_EXISTS,
    ENU_FILE_RSP_FILE_LENGTH_ERROR,                     // invalid file length on write close
    ENU_FILE_RSP_FILE_CRC_ERROR,                        // invalid file crc on write close
    ENU_FILE_RSP_UNABLE_TO_UPDATE_EXISTING_BASENAME,
    ENU_FILE_RSP_UNABLE_TO_CREATE_NEW_BASENAME,
    ENU_FILE_RSP_RETRIEVE_BASENAME_ERROR,
    ENU_FILE_RSP_RETRIEVE_FILENAME_ERROR,
    ENU_FILE_RSP_BASENAME_LIST_ERROR,                   // unable to get basename list from database
    ENU_FILE_RSP_FILE_SIZE_TOO_LARGE,                   // read file exceeds size of user requested max
    ENU_FILE_RSP_DATA_FILE_LENGTH_ERROR,                // file length error in write data request
    ENU_FILE_RSP_DATA_FILE_OFFSET_ERROR,                // file offset error in write data request
    ENU_FILE_RSP_DELETE_VERSION_ERROR,                  // file delete by basename version failed
    ENU_FILE_RSP_DELETE_BASENAME_ERROR,                 // delete basename failed
    ENU_FILE_RSP_DELETE_KEYNAME_ERROR,                  // file delete by database keyname failed
    ENU_FILE_RSP_PURGE_BASENAME_FAILED,
    // error codes from Coldfire
    ENU_FILE_RSP_RECEIVE_TIMEOUT = 100,
    ENU_FILE_RSP_INVALID_RXDATA_STRING,
    ENU_FILE_RSP_INVALID_RXDATA_FILE_VER,
    ENU_FILE_RSP_INVALID_RXDATA_PKT_OFFSET,
    ENU_FILE_RSP_INVALID_RXDATA_PKT_LENGTH,
    ENU_FILE_RSP_INVALID_RXDATA_FILE_LENGTH,
    ENU_FILE_RSP_RECEIVE_FILE_CRC_ERROR,						// crc errror in received file
    ENU_FILE_RSP_BASENAME_LIST_PARSE_ERROR,
    ENU_FILE_RSP_BASENAME_LIST_LENGTH
} FILE_RSP_ENU;

/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


#endif // QUARTZ_COMM_FILE_DEFINES_H


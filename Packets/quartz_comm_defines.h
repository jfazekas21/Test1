/******************************************************************************
*				File:				quartz_comm_defines.h										*
*  			Description:	Communication Base Definitions							*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_DEFINES_H
#define QUARTZ_COMM_DEFINES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/

#define DEF_MAX_NUM_PORT								4					// number of test ports 
#define DEF_MAX_NUM_DUT									4					// number of device-under-test

#define DEF_MAX_NUM_SUBGROUP							10					// number of sub-groups executed per dut
#define DEF_MAX_NUM_OBJECT								255				// number of objects in lists
#define DEF_MAX_NUM_NODE_PIN							6					// number of pins per node
#define DEF_MAX_NUM_NET_CONNECTION					10					// number of connections per net
#define DEF_MAX_NUM_VARIABLE							50					// number of variables in lists
#define DEF_MAX_NUM_VARIABLE_ARRAY					33					// number of individual items in the array variables
#define DEF_MAX_LEN_ASCII_VARIABLE					51					// number of bytes in ASCII string variable

#define DEF_MAX_NUM_STREAM_VARIABLE					8					// number of variables per streaming packet

#define DEF_MAX_NUM_RESULT_VARIABLE					20					// number of variables per result

/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


#endif // QUARTZ_COMM_DEFINES_H


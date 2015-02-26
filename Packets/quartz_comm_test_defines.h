/******************************************************************************
*				File:				quartz_comm_test_defines.h									*
*  			Description:	Communications Test Definitions							*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_TEST_DEFINES_H
#define QUARTZ_COMM_TEST_DEFINES_H

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

typedef enum								// test payload command codes
{
	ENU_CMD_TEST_UNDEF,						// undefined command code
	ENU_CMD_TEST_INVALID,					// interpreted packet was invalid (error response)
	ENU_CMD_TEST_ACTIVE_GROUP_GET,		// gets the current active group
	ENU_CMD_TEST_ACTIVE_GROUP_SET,		// sets the current active group
	ENU_CMD_TEST_LOAD_GROUP,				// test load specific group 
	ENU_CMD_TEST_LOAD_DUT,					// test load device-under test
	ENU_CMD_TEST_LOAD_SUB_GROUP,			// test load sub-group 
	ENU_CMD_TEST_STATUS_REQ,				// test status request
	ENU_CMD_TEST_STATUS_GROUP,				// test group status
	ENU_CMD_TEST_STATUS_DUT,				// test device-under-test status
	ENU_CMD_TEST_STATUS_SUB_GROUP,		// test sub-group status
	ENU_CMD_TEST_UNIQUE_ID_REQ,			// test unique id request
	ENU_CMD_TEST_UNIQUE_ID,					// test unique id
	ENU_CMD_TEST_SIGNAL_NOTIFY,			// test signal notification
	ENU_CMD_TEST_EVENT_LIST_REQ,			// test event list status request
	ENU_CMD_TEST_EVENT_LIST_BEGIN,		// test event list status begin
	ENU_CMD_TEST_SIGNAL_STATUS_LIST,		// test signal status list content
	ENU_CMD_TEST_EVENT_STATUS_LIST,		// test event status list content
	ENU_CMD_TEST_EVENT_LIST_END,			// test event list status end
	ENU_CMD_TEST_SIGNAL_STATUS,			// test signal status (real-time) notification
	ENU_CMD_TEST_EVENT_STATUS,				// test event status (real-time) notification
	ENU_CMD_TEST_STREAM,						// test streaming data (real-time output)
	ENU_CMD_TEST_RESULT_NODE,				// test result node data
	ENU_CMD_TEST_RESULT_VARIABLE,			// test result variable data
	ENU_CMD_TEST_RESULT_SUB_GROUP,		// test result subgroup data	
	ENU_CMD_TEST_RESULT_DUT,				// test result device-under-test data
	ENU_CMD_TEST_USER_PROMPT,				// test streaming user prompt
	ENU_CMD_TEST_MAX
} TEST_CMD_ENU;

typedef enum								// test port type codes
{
	ENU_TEST_PORT_TYPE_UNDEF,				// undefined port type
	ENU_TEST_PORT_TYPE_SINGLE,				// single slot port
	ENU_TEST_PORT_TYPE_DOUBLE_A,			// double slot port, style A
	ENU_TEST_PORT_TYPE_DOUBLE_B,			// double slot port, style B
	ENU_TEST_PORT_TYPE_TRIPLE_A,			// triple slot port, style A
	ENU_TEST_PORT_TYPE_TRIPLE_B,			// triple slot port, style B
	ENU_TEST_PORT_TYPE_TRIPLE_C,			// triple slot port, style C
	ENU_TEST_PORT_TYPE_QUAD_A,				// quad slot port, style A
	ENU_TEST_PORT_TYPE_QUAD_B,				// quad slot port, style B
	ENU_TEST_PORT_TYPE_QUAD_C,				// quad slot port, style C
	ENU_TEST_PORT_TYPE_QUAD_D,				// quad slot port, style D
	ENU_TEST_PORT_TYPE_MAX	
} TEST_PORT_TYPE_ENU;

typedef enum								// test group status codes
{
	ENU_TEST_STATUS_GROUP_UNDEF,			// undefined test status
	ENU_TEST_STATUS_GROUP_IDLE,			// test mode idle, valid configuration
	ENU_TEST_STATUS_GROUP_ACTIVE,			// actively testing, with provided configuration
	ENU_TEST_STATUS_GROUP_ERROR,			// error mode, invalid configuration
	ENU_TEST_STATUS_GROUP_EDIT,			// testing disabled, currently locked in edit mode
	ENU_TEST_STATUS_GROUP_MAX
} TEST_STATUS_GROUP_ENU;

typedef enum								// device-under-test status codes
{
	ENU_TEST_STATUS_DUT_UNDEF,				// undefined test status
	ENU_TEST_STATUS_DUT_IDLE,				// device-under-test idle, valid configuration
	ENU_TEST_STATUS_DUT_ACTIVE,			// actively testing, with provided configuration
	ENU_TEST_STATUS_DUT_ERROR,				// error mode, invalid configuration
	ENU_TEST_STATUS_DUT_MAX
} TEST_STATUS_DUT_ENU;

typedef enum								// device-under-test flags (note multiple flags can be active at once)
{
	ENU_FLAG_DUT_UNDEF						// no active flags
} TEST_FLAG_DUT_ENU;

typedef enum								// sub-group status codes
{
	ENU_TEST_STATUS_SUB_GROUP_UNDEF,		// undefined test status
	ENU_TEST_STATUS_SUB_GROUP_IDLE,		// sub-group idle, valid configuration
	ENU_TEST_STATUS_SUB_GROUP_ACTIVE,	// actively testing, with provided configuration
	ENU_TEST_STATUS_SUB_GROUP_ERROR,		// error mode, invalid configuration
	ENU_TEST_STATUS_SUB_GROUP_MAX
} TEST_STATUS_SUB_GROUP_ENU;

typedef enum								// sub-group flags (note multiple flags can be active at once)
{
	ENU_FLAG_SUB_GROUP_UNDEF				// no active flags
} TEST_FLAG_SUB_GROUP_ENU;

typedef enum								// test control codes
{
	ENU_TEST_CONTROL_UNDEF,					// undefined test control
	ENU_TEST_CONTROL_START,					// test control start request
	ENU_TEST_CONTROL_STOP,					// test control stop request
	ENU_TEST_CONTROL_MAX							
} TEST_CONTROL_ENU;	

typedef enum								// event state codes
{
	ENU_EVENT_STATE_CLEAR,					// event state currently cleared 
	ENU_EVENT_STATE_SET,						// event state currently set
	ENU_EVENT_STATE_REQ_CLEAR,				// event state request to clear (commanded action)
	ENU_EVENT_STATE_REQ_SET,				// event state request to set (commanded action)
	ENU_EVENT_STATE_MAX
} EVENT_STATE_ENU;

typedef enum								// event edge codes
{
	ENU_EVENT_EDGE_CLEAR,					// event edge currently cleared
	ENU_EVENT_EDGE_RISE,						// rising event edge detected (last state change was rising)
	ENU_EVENT_EDGE_FALL,						// falling event edge detected (last state change was falling)
	ENU_EVENT_EDGE_REQ_CLEAR,				// event edge request to clear
	ENU_EVENT_EDGE_MAX
} EVENT_EDGE_ENU;

typedef enum								// signal state codes
{
	ENU_SIGNAL_STATE_CLEAR,					// signal state currently cleared 
	ENU_SIGNAL_STATE_SET,					// signal state currently set
	ENU_SIGNAL_STATE_MAX
} SIGNAL_STATE_ENU;

typedef enum								// streaming mode codes
{
	ENU_TEST_STREAM_UNDEF,					// undefined stream code
	ENU_TEST_STREAM_DUT,						// device-under-test streaming packet
	ENU_TEST_STREAM_SUB_GROUP,				// sub-group streaming packet
	ENU_TEST_STREAM_MAX
} TEST_STREAM_ENU;

typedef enum								// result type codes
{
	ENU_TEST_RESULT_UNDEF,
	ENU_TEST_RESULT_DUT,						// device-under-test result packet
	ENU_TEST_RESULT_SUB_GROUP,				// sub-group result packet
	ENU_TEST_RESULT_MAX
} TEST_RESULT_ENU;

typedef enum								// stream slot codes
{
	ENU_TEST_STREAM_SLOT_NONE,				// non-displayed streaming value									
	ENU_TEST_STREAM_SLOT_1,					// slot priority number
	ENU_TEST_STREAM_SLOT_2,						
	ENU_TEST_STREAM_SLOT_3,
	ENU_TEST_STREAM_SLOT_4,
	ENU_TEST_STREAM_SLOT_5,
	ENU_TEST_STREAM_SLOT_6,
	ENU_TEST_STREAM_SLOT_7,
	ENU_TEST_STREAM_SLOT_8,
	ENU_TEST_STREAM_SLOT_9,
	ENU_TEST_STREAM_SLOT_10,
	ENU_TEST_STREAM_SLOT_MAX
} TEST_STREAM_SLOT_ENU;

typedef enum								// result slot codes
{
	ENU_TEST_RESULT_SLOT_NONE,				// undefined slot 
	ENU_TEST_RESULT_SLOT_EVAL,				// reserved slot - evaluation 
	ENU_TEST_RESULT_SLOT_DATE,				// reserved slot - date
	ENU_TEST_RESULT_SLOT_TIME,				// reserved slot - time
	ENU_TEST_RESULT_SLOT_FLAG,				// reserved slot - flags
	ENU_TEST_RESULT_BARCODE,				// reserved slot - barcode 
	ENU_TEST_RESULT_BATCHLOT,				// reserved slot - batch/lot code
	ENU_TEST_RESULT_SLOT_TEST_TYPE,		// reserved slot - test type
	ENU_TEST_RESULT_SLOT_1,					// general slot - non-specific data - priority 1
	ENU_TEST_RESULT_SLOT_2,					// general slot - non-specific data - priority 2
	ENU_TEST_RESULT_SLOT_3,					// general slot - non-specific data - priority 3
	ENU_TEST_RESULT_SLOT_4,					// general slot - non-specific data - priority 4
	ENU_TEST_RESULT_SLOT_5,					// general slot - non-specific data - priority 5
	ENU_TEST_RESULT_SLOT_6,					// general slot - non-specific data - priority 6
	ENU_TEST_RESULT_SLOT_7,					// general slot - non-specific data - priority 7
	ENU_TEST_RESULT_SLOT_8,					// general slot - non-specific data - priority 8
	ENU_TEST_RESULT_SLOT_9,					// general slot - non-specific data - priority 9
	ENU_TEST_RESULT_SLOT_MAX
} TEST_RESULT_SLOT_ENU;


typedef enum								// test stream flags (note multiple flags can be active at once)
{
	ENU_TEST_STREAM_FLAG_UNDEF,			// no active flags
	ENU_TEST_STREAM_FLAG_HOLD,				// test flag - Hold mode
	ENU_TEST_STREAM_FLAG_AUTOCAL,			// test flag - Autocal active
	ENU_TEST_STREAM_FLAG_LEAK_STD			// test flag - Leak Standard active
} TEST_STREAM_FLAG_ENU;	
			
#define TEST_FLAG(x)					(1<<x)	



/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/

#define DEF_TEST_FLAG_DUT_MASK			(	0 	)

#define DEF_FLAG_SUB_GROUP_MASK			(	0 	)

#define DEF_TEST_STREAM_FLAG_MASK		(	TEST_FLAG(ENU_TEST_STREAM_FLAG_HOLD) |				\
														TEST_FLAG(ENU_TEST_STREAM_FLAG_AUTOCAL) |			\
														TEST_FLAG(ENU_TEST_STREAM_FLAG_LEAK_STD) )


#endif // QUARTZ_COMM_TEST_DEFINES_H


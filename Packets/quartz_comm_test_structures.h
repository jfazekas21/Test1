/******************************************************************************
*				File:				quartz_comm_test_structures.h								*
*  			Description:	Communications Test Structure Definitions				*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_TEST_STRUCTURES_H
#define QUARTZ_COMM_TEST_STRUCTURES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_structures.h"					// Communications Base Structures
#include "quartz_comm_test_defines.h"				// Communications Test Defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


// *** ENU_CMD_TEST_ACTIVE_GROUP_GET - gets the current active group
// *** ENU_CMD_TEST_ACTIVE_GROUP_SET - sets the current active group

typedef struct		test_active_group_req_struct			// test active group request structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]	
} TEST_ACTIVE_GROUP_REQ_STR;

typedef struct		test_active_group_struct				// test sub_group structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]	
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_8						reserved_3;							// reserved byte (alignment)	
	OBJECT_STR					str_group;							// group object
} TEST_ACTIVE_GROUP_STR;


// *** ENU_CMD_TEST_LOAD_GROUP - test load specific group 

typedef struct		test_port_info_struct					// test port structure
{
	uint_8						port_num;							// port number
	uint_8						port_type;							// port [TEST_PORT_TYPE_ENU]
	uint_8						hw_slot_num;						// physical hardware slot number
	uint_8						reserved_1;							// reserved byte (alignment)
} TEST_PORT_INFO_STR;

	typedef struct		test_load_group_struct						// test load group structure
	{
		uint_8						command;										// command code [TEST_CMD_ENU]
		uint_8						reserved_1;									// reserved byte (alignment)
		uint_8						reserved_2;									// reserved byte (alignment)
		uint_8						reserved_3;									// reserved byte (alignment)
		OBJECT_STR					str_group;									// group object
		uint_8						num_port;									// number of ports
		uint_8						num_dut;										// number of device-under test items
		uint_8						reserved_4;									// reserved byte (alignment)
		uint_8						reserved_5;									// reserved byte (alignment)
		TEST_PORT_INFO_STR		str_port_list[DEF_MAX_NUM_PORT];		// port information
	} TEST_LOAD_GROUP_STR;	

	
// *** ENU_CMD_TEST_LOAD_DUT - test load device-under test
	
typedef struct		test_load_dut_struct							// test load device-under-test structure
{
	uint_8						command;										// command code [TEST_CMD_ENU]
	uint_8						reserved_1;									// reserved byte (alignment)
	uint_8						reserved_2;									// reserved byte (alignment)
	uint_8						reserved_3;									// reserved byte (alignment)
	OBJECT_STR					str_group;									// group object
	uint_8						dut_num;										// device-under-test number 
	uint_8						dut_name[DEF_MAX_LEN_ASCII_VARIABLE];	// device-under-test name
	uint_8						num_sub_group;								// number of sub-group items
}	TEST_LOAD_DUT_STR;


// *** ENU_CMD_TEST_LOAD_SUB_GROUP - test load sub-group 

typedef struct		test_load_subgroup_struct					// test load sub_group structure
{
	uint_8						command;										// command code [TEST_CMD_ENU]
	uint_8						reserved_1;									// reserved byte (alignment)
	uint_8						reserved_2;									// reserved byte (alignment)
	uint_8						reserved_3;									// reserved byte (alignment)
	OBJECT_STR					str_group;									// group object
	uint_8						dut_num;										// device-under-test number 
	uint_8						port_num;									// port number		
	uint_8						reserved_4;									// reserved byte (alignment)
	uint_8						reserved_5;									// reserved byte (alignment)
	OBJECT_STR					str_sub_group;								// sub-group object
	uint_8						sub_group_name[DEF_MAX_LEN_ASCII_VARIABLE];	// sub-group name
} TEST_LOAD_SUB_GROUP_STR;

	
// *** ENU_CMD_TEST_STATUS_REQ - test status request

typedef struct		test_status_req_struct					// status request structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]
} TEST_STATUS_REQ_STR;


// *** ENU_CMD_TEST_STATUS_GROUP - test group status

typedef struct		test_group_status_struct				// group status structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_8						reserved_3;							// reserved byte (alignment)
	OBJECT_STR					str_group;							// group object
	uint_8						group_status;						// group status code [TEST_STATUS_GROUP_ENU]
} TEST_GROUP_STATUS_STR;


// *** ENU_CMD_TEST_STATUS_DUT - test device-under-test status

typedef struct		test_dut_status_struct					// device-under-test status structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]
	uint_8						dut_num;								// device-under-test number
	uint_8						dut_status;							// device-under-test status code [TEST_STATUS_DUT_ENU]
	uint_8						flags;								// device-under-test flags  [TEST_FLAG(TEST_FLAG_DUT_ENU)]
	uint_32						last_result_id;					// unique identifier of the last result
} TEST_DUT_STATUS_STR;


// *** ENU_CMD_TEST_STATUS_SUB_GROUP - test sub-group status

typedef struct		test_sub_group_status_struct			// sub-group status structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]
	uint_8						dut_num;								// device-under-test number
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	OBJECT_STR					str_sub_group;						// sub-group object
	uint_8						sub_group_status;					// sub-group status code [TEST_STATUS_SUB_GROUP_ENU]
	uint_8						flags;								// device-under-test flags  [TEST_FLAG(TEST_FLAG_SUB_GROUP_ENU)]
	uint_8						reserved_3;							// reserved byte (alignment)
	uint_8						reserved_4;							// reserved byte (alignment)
	uint_32						last_result_id;					// unique identifier of the last result
} TEST_SUB_GROUP_STATUS_STR;


// *** ENU_CMD_TEST_UNIQUE_ID_REQ - test unique id request

typedef struct		test_unique_id_req						// test unique id request 
{
	uint_8						command;								// command code [TEST_CMD_ENU]
} TEST_UNIQUE_ID_REQ_STR;


// *** ENU_CMD_TEST_UNIQUE_ID - test unique id

typedef struct		test_unique_id								// test unique id
{
	uint_8						command;								// command code [TEST_CMD_ENU]
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_8						reserved_3;							// reserved byte (alignment)
	uint_32						unique_id;							// unique id
} TEST_UNIQUE_ID_STR;


// *** ENU_CMD_TEST_SIGNAL_NOTIFY - test signal notification

typedef struct		test_signal_notify_struct				// test signal notification structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_8						reserved_3;							// reserved byte (alignment)
	OBJECT_STR					str_signal;							// signal object
	uint_8						signal_state;						// signal state [SIGNAL_STATE_ENU]
} TEST_SIGNAL_NOTIFY_STR;


// *** ENU_CMD_TEST_EVENT_LIST_REQ - test event list status request
	
typedef struct		test_list_event_req_struct				// test event data request structure
{
	uint_8						command;								// command code [ENU_CMD_TEST_EVENT]
} TEST_LIST_EVENT_REQ_STR;


// *** ENU_CMD_TEST_EVENT_LIST_BEGIN - test event list status begin
		
typedef struct		test_list_event_begin_struct		// test event data list begin structure
{
	uint_8						command;								// command code [ENU_CMD_TEST_EVENT]
} TEST_LIST_EVENT_BEGIN_STR;


// *** ENU_CMD_TEST_EVENT_LIST_END - test event list status end
		
typedef struct		test_list_event_end_struct		// test event data list end structure
{
	uint_8						command;								// command code [ENU_CMD_TEST_EVENT]
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_8						reserved_3;							// reserved byte (alignment)
	uint_32						num_signal;							// number of signals
	uint_32						num_event;							// number of events 		
} TEST_LIST_EVENT_END_STR;


// *** ENU_CMD_TEST_SIGNAL_STATUS_LIST - test event status list content
// *** ENU_CMD_TEST_SIGNAL_STATUS - test signal status (real-time) notification

typedef struct		test_signal_status_struct				// test event status structure 
{
	uint_8						command;								// command code [ENU_CMD_TEST_EVENT_ANNOUNCE]
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_8						signal_state;						// signal state [SIGNAL_STATE_ENU] (note: re-ordered for reduced packet size)
	OBJECT_STR					str_signal;							// signal object
} TEST_SIGNAL_STATUS_STR;	


// *** ENU_CMD_TEST_EVENT_STATUS_LIST - test event status list content
// *** ENU_CMD_TEST_EVENT_STATUS - test event status (real-time) notification

typedef struct		test_event_status_struct				// test event status structure 
{
	uint_8						command;								// command code [ENU_CMD_TEST_EVENT_ANNOUNCE]
	uint_8						dut_num;								// device-under-test number (note: re-ordered for reduced packet size)
	uint_8						event_state;						// event state [EVENT_STATE_ENU]
	uint_8						event_edge;							// event edge [EVENT_EDGE_ENU]
	OBJECT_STR					str_group;							// group object
	OBJECT_STR					str_sub_group;						// sub-group object
	OBJECT_STR					str_node;							// node object
	OBJECT_STR					str_event;							// event object
} TEST_EVENT_STATUS_STR;	


// *** ENU_CMD_TEST_STREAM - Test operation packets - test streaming data (real-time output)

typedef union		test_stream_var_content_union				// test stream variable contents union
{
	VARIABLE_INT_STR			str_int;
	VARIABLE_FLOAT_STR		str_float;
	VARIABLE_DOUBLE_STR		str_double;
	OBJECT_STR					str_cond;
} TEST_STREAM_VAR_UNI;	

	typedef struct		test_stream_var_struct					// test stream variable structure 
	{
		OBJECT_STR					str_var;								// variable object
		uint_8						slot_num;							// variable screen slot location [TEST_STREAM_SLOT_ENU]
		uint_8						reserved_1;							// reserved byte (alignment)
		uint_8						reserved_2;							// reserved byte (alignment)
		uint_8						reserved_3;							// reserved byte (alignment)
		TEST_STREAM_VAR_UNI		uni_data;							// variable data union		
	} TEST_STREAM_VAR_STR;	
		
		typedef struct		test_stream_struct						// test streaming data structure
		{
			uint_8						command;								// command code [TEST_CMD_ENU]
			uint_8						stream_mode;						// streaming mode [TEST_STREAM_ENU]
			uint_8						dut_num;								// device-under-test number
			uint_8						port_num;							// port number
			OBJECT_STR					str_group;							// group object
			OBJECT_STR					str_sub_group;						// sub-group object
			OBJECT_STR					str_node;							// node object			
			uint_8						flags;								// test flags [TEST_FLAG(TEST_STREAM_FLAG_ENU)]
			uint_8						num_var;								// number of entries in variable list
			uint_8						reserved_1;							// reserved byte (alignment)
			uint_8						reserved_2;							// reserved byte (alignment)
			TEST_STREAM_VAR_STR		str_var_list[DEF_MAX_NUM_STREAM_VARIABLE];		// variable list
		} TEST_STREAM_STR;

		#define TEST_STREAM_SIZE(x) 		(offsetof(TEST_STREAM_STR, str_var_list) + (x * sizeof(TEST_STREAM_VAR_STR)))


// *** ENU_CMD_TEST_RESULT_NODE - test result node data

typedef struct    test_result_node_struct					// test result node structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]
	uint_8						dut_num;								// device-under-test number			
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_32						unique_id;							// unique identifier for this result
	OBJECT_STR					str_group;							// group object
	OBJECT_STR					str_sub_group;						// sub-group object (this will be zero if it is not part of a sub-group)
	OBJECT_STR					str_node;							// node object		
	uint_8                  num_var;                   	// number of result variables for this node		
} TEST_RESULT_NODE_STR;	


// *** ENU_CMD_TEST_RESULT_VARIABLE - test result variable data

typedef union		test_result_var_content_union			// test result variable contents union
{
	VARIABLE_INT_STR			str_int;
	VARIABLE_INT_ARR_STR		str_int_arr;
	VARIABLE_FLOAT_STR		str_float;
	VARIABLE_FLOAT_ARR_STR	str_float_arr;
	VARIABLE_DOUBLE_STR		str_double;
	OBJECT_STR					str_cond;
	VARIABLE_ASCII_STR		str_ascii;
} TEST_RESULT_VAR_UNI;	

	typedef struct    test_result_var_struct					// test result variable structure
	{
		uint_8						command;								// command code [TEST_CMD_ENU]
		uint_8						dut_num;								// device-under-test number
		uint_8						slot_type;							// result slot type [TEST_RESULT_SLOT_ENU]				
		uint_8						reserved_1;							// reserved byte (alignment)
		uint_32						unique_id;							// unique identifier for this result
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_sub_group;						// sub-group object (this will be zero if it is not part of a sub-group)
		OBJECT_STR					str_node;							// node object		
		OBJECT_STR					str_var;								// variable object
		TEST_RESULT_VAR_UNI		uni_data;							// variable data union
	} TEST_RESULT_VAR_STR;


// *** ENU_CMD_TEST_RESULT_SUB_GROUP - test result subgroup data

typedef struct		test_result_sub_group_struct			// test result sub-group structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]
	uint_8						dut_num;								// device-under-test number			
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_32						unique_id;							// unique identifier for this result
	OBJECT_STR					str_group;							// group object
	OBJECT_STR					str_sub_group;						// sub-group object 
	uint_8                  num_node;          				// number of result nodes for this sub-group
} TEST_RESULT_SUB_GROUP_STR;


// *** ENU_CMD_TEST_RESULT_DUT - test result device-under-test data

typedef struct		test_result_dut_struct					// test result device-under-test structure
{
	uint_8						command;								// command code [TEST_CMD_ENU]
	uint_8						dut_num;								// device-under-test number			
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_32						unique_id;							// unique identifier for this result
	OBJECT_STR					str_group;							// group object
	OBJECT_STR					str_eval;							// evaluation object	
	uint_8                  num_node;          	      	// number of result nodes for this dut (will include sub-groups)
	uint_8						num_sub_group;						// number of sub-groups for this dut
} TEST_RESULT_DUT_STR;


	// *** Communications Payload - Test packets union	
	typedef union	payload_test_union
	{
		uint_8								command;
		TEST_ACTIVE_GROUP_REQ_STR		str_active_group_req;
		TEST_ACTIVE_GROUP_STR			str_active_group;
		TEST_LOAD_GROUP_STR				str_load_group;
		TEST_LOAD_DUT_STR					str_load_dut;
		TEST_LOAD_SUB_GROUP_STR			str_load_sub_group;			
		TEST_STATUS_REQ_STR				str_status_req;
		TEST_GROUP_STATUS_STR			str_status_group;
		TEST_DUT_STATUS_STR				str_status_dut;
		TEST_SUB_GROUP_STATUS_STR		str_status_sub_group;
		TEST_UNIQUE_ID_REQ_STR			str_unique_id_req;
		TEST_UNIQUE_ID_STR				str_unique_id;
		TEST_SIGNAL_NOTIFY_STR			str_signal_notify;
		TEST_LIST_EVENT_REQ_STR			str_event_list_req;	
		TEST_LIST_EVENT_BEGIN_STR		str_event_list_begin;
		TEST_LIST_EVENT_END_STR			str_event_list_end;
		TEST_SIGNAL_STATUS_STR			str_signal_status;
		TEST_EVENT_STATUS_STR			str_event_status;
		TEST_STREAM_STR					str_stream;
		TEST_RESULT_NODE_STR				str_result_node;
		TEST_RESULT_VAR_STR				str_result_variable;
		TEST_RESULT_SUB_GROUP_STR		str_result_sub_group;
		TEST_RESULT_DUT_STR				str_result_dut;
} PAYLOAD_TEST_UNI;


#endif // QUARTZ_COMM_TEST_STRUCTURES_H


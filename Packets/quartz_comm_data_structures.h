/******************************************************************************
*				File:				quartz_comm_data_structures.h								*
*  			Description:	Communications Data Structure Definitions				*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_DATA_STRUCTURES_H
#define QUARTZ_COMM_DATA_STRUCTURES_H

/*--------------------------------------------------------------------------*/
/*                            INCLUDES                                      */
/*--------------------------------------------------------------------------*/

#include "quartz_comm_structures.h"					// Communications Base Structures
#include "quartz_comm_data_defines.h"				// Communications Data Defines

/*--------------------------------------------------------------------------*/
/*                            CONSTANT DEFINITIONS                          */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            ENUMS                                         */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/

typedef struct	data_revision_struct							// data revision structure (used for group lists)
{
	uint_16						num;									// element number
	uint_16						revision;							// revision number
} DATA_REVISION_STR;		

typedef struct		node_info_struct							// node information structure (node addressing and pin list)
{
	OBJECT_STR					str_node;							// node object 
	uint_8						root_index;							// node root index [ROOT_INDEX_ENU]
	uint_8						num_pin;								// number of pins in list
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	OBJECT_STR					str_pin_list[DEF_MAX_NUM_NODE_PIN];	// pin object list
} NODE_INFO_STR;	

typedef struct		net_connection_struct					// net connection structure (node/pin connections)
{
	OBJECT_STR					str_node;							// node object 
	OBJECT_STR					str_pin;								// pin object 
} NET_CONNECT_STR;				

typedef struct		net_info_struct							// net information structure (net addressing and connection list)
{
	OBJECT_STR					str_net;								// net object 
	uint_8						num_connect;						// number of connections in list
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	uint_8						reserved_3;							// reserved byte (alignment)
	NET_CONNECT_STR			str_connect_list[DEF_MAX_NUM_NET_CONNECTION];	// connection list
} NET_INFO_STR;	

typedef struct		action_var_struct							// action variable structure
{
	OBJECT_STR					str_action;							// action object 
	OBJECT_STR					str_cond;							// conditional object 
	OBJECT_STR					str_target;							// target object 
} ACTION_VAR_STR;

typedef union		data_var_content_union					// data variable contents union
{
	VARIABLE_INT_STR			str_int;
	VARIABLE_INT_ARR_STR		str_int_arr;
	VARIABLE_FLOAT_STR		str_float;
	VARIABLE_FLOAT_ARR_STR	str_float_arr;
	VARIABLE_DOUBLE_STR		str_double;
	OBJECT_STR					str_cond;
	VARIABLE_ASCII_STR		str_ascii;
} DATA_VAR_UNI;	
	
typedef struct		data_var_struct							// data variable structure 
{
	OBJECT_STR					str_var;								// variable object
	uint_8						edit;									// edit style
	uint_8						attribute;							// attribute 
	uint_8						reserved_1;							// reserved byte (alignment)
	uint_8						reserved_2;							// reserved byte (alignment)
	DATA_VAR_UNI				uni_data;							// variable data union		
} DATA_VAR_STR;


	// *** ENU_CMD_DATA_LIST_TYPES - Configuration data packets - list all available types of groups

	typedef struct		data_list_types_req_struct				// data request list group types structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
	} DATA_LIST_GROUP_TYPE_REQ_STR;

	typedef struct		data_list_types_struct					// data list group types structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						num_group;							// number of group types in list
		OBJECT_STR					str_list[DEF_MAX_NUM_OBJECT];	// group list (code, number of items per code)
	} DATA_LIST_GROUP_TYPE_STR;


	#define DATA_LIST_GROUP_TYPE_SIZE(x)	(offsetof(DATA_LIST_GROUP_TYPE_STR, str_list) + (x * sizeof(OBJECT_STR)))


	// *** ENU_CMD_DATA_GROUP_ATTRIBUTE_REQ - Configuration data packets - within group, list all attribute variables (with data)
	// *** ENU_CMD_DATA_GROUP_ATTRIBUTE - Configuration data packets - within group, list attribute variables

    typedef struct		data_list_group_attribute_req_struct	// data request list variable structure
    {
        uint_8						command;								// command code [DATA_CMD_ENU]
        uint_8						user_level;							// HMI user level
        uint_8						security_level;					// HMI security level
        uint_8						var_sub_type;						// HMI variable sub type
        OBJECT_STR				str_group;							// group object
    } DATA_LIST_GROUP_ATTRIBUTE_REQ_STR;

    typedef struct		data_list_group_attribute_struct			// data list variable structure
    {
        uint_8						command;								// command code [DATA_CMD_ENU]
        uint_8						user_level;							// HMI user level
        uint_8						security_level;					// HMI security level
        uint_8						var_sub_type;						// HMI variable sub type
        OBJECT_STR				str_group;							// group object
        uint_8						num_var;								// number of variables in list
        uint_8						reserved_2;							// reserved byte (alignment)
        uint_8						reserved_3;							// reserved byte (alignment)
        uint_8						reserved_4;							// reserved byte (alignment)
        DATA_VAR_STR				str_list[DEF_MAX_NUM_VARIABLE];	// variable list
    } DATA_LIST_GROUP_ATTRIBUTE_STR;


	// *** ENU_CMD_DATA_GROUP_ADD - Add group
	
    typedef struct		data_group_add_struct						// data request to add a group
    {
        uint_8						command;								// command code [DATA_CMD_ENU]
        uint_8						user_level;							// HMI user level
        uint_8						security_level;					// HMI security level
        uint_8						reserved_1;							// reserved byte (alignment)
    } DATA_GROUP_ADD_STR;


	// *** ENU_CMD_DATA_LIST_GROUP - Configuration data packets - list all available groups of specified type (along with the revision level of the group)

	typedef struct		data_list_group_req_struct				// data request list group structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		uint_16						group_code;							// group code
	} DATA_LIST_GROUP_REQ_STR;

	typedef struct		data_list_group_struct					// data list group structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		uint_16						group_code;							// group code
		uint_8						num_group;							// number of groups in list
		uint_8						reserved_2;							// reserved byte (alignment)
		DATA_REVISION_STR			str_list[DEF_MAX_NUM_OBJECT];	// group list (number, revision)
	} DATA_LIST_GROUP_STR;

	#define DATA_LIST_GROUP_SIZE(x)	(offsetof(DATA_LIST_GROUP_STR, str_list) + (x * sizeof(DATA_REVISION_STR)))




	// *** ENU_CMD_DATA_GROUP_LIST_NODE - Configuration data packets - within group, list nodes

	typedef struct		data_list_node_req_struct				// data request list node structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
	} DATA_LIST_NODE_REQ_STR;

	typedef struct		data_list_node_struct					// data list node structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		uint_8						num_node;							// number of nodes in list
		uint_8						reserved_2;							// reserved byte (alignment)
		uint_8						reserved_3;							// reserved byte (alignment)
		uint_8						reserved_4;							// reserved byte (alignment)
		NODE_INFO_STR				str_list[DEF_MAX_NUM_OBJECT];	// node list
	} DATA_LIST_NODE_STR;

	#define DATA_LIST_NODE_SIZE(x) 	(offsetof(DATA_LIST_NODE_STR, str_list) + (x * sizeof(NODE_INFO_STR)))


	// *** ENU_CMD_DATA_GROUP_LIST_NET - Configuration data packets - within group, list nets (and connections)

	typedef struct		data_list_net_req_struct				// data request list net structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
	} DATA_LIST_NET_REQ_STR;

	typedef struct		data_list_net_struct						// data list net structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		uint_8						num_net;								// number of nets in list
		uint_8						reserved_2;							// reserved byte (alignment)
		uint_8						reserved_3;							// reserved byte (alignment)
		uint_8						reserved_4;							// reserved byte (alignment)
		NET_INFO_STR				str_list[DEF_MAX_NUM_OBJECT];	// net list
	} DATA_LIST_NET_STR;

	#define DATA_LIST_NET_SIZE(x) 	(offsetof(DATA_LIST_NET_STR, str_list) + (x * sizeof(NET_INFO_STR)))


	// *** ENU_CMD_DATA_NODE_GROUP_LINK - Configuration data packets - with node, indicate link to group
	
	typedef struct		data_node_group_link_req_struct		// data request node-to-group link structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
	} DATA_NODE_LINK_REQ_STR;

	typedef struct		data_node_group_link_struct			// data node-to-group link structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
		OBJECT_STR					str_link_group;					// link to group object
	} DATA_NODE_LINK_STR;


	// *** ENU_CMD_DATA_NODE_LIST_ACTION - Configuration data packets - node list actions

	typedef struct		data_list_node_action_req_struct		// data request list node actions structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
	} DATA_LIST_NODE_ACTION_REQ_STR;

	typedef struct		data_list_node_action_struct			// data list node actions structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
		uint_8						num_action;							// number of actions in list
		uint_8						reserved_2;							// reserved byte (alignment)
		uint_8						reserved_3;							// reserved byte (alignment)
		uint_8						reserved_4;							// reserved byte (alignment)
		ACTION_VAR_STR				str_list[DEF_MAX_NUM_OBJECT];	// action list
	} DATA_LIST_NODE_ACTION_STR;
	
	#define DATA_LIST_NODE_ACTION_SIZE(x) 		(offsetof(DATA_LIST_NODE_ACTION_STR, str_list) + (x * sizeof(ACTION_VAR_STR)))


	// *** ENU_CMD_DATA_NODE_SET_ACTION - Configuration data packets - node set action

	typedef struct		data_node_action_set_struct			// data set node action structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
		ACTION_VAR_STR				str_action;							// action
	} DATA_NODE_ACTION_SET_STR;


	// *** ENU_CMD_DATA_NODE_LIST_ATTRIBUTE - Configuration data packets - within node, list all attribute variables (with data)
	// *** ENU_CMD_DATA_NODE_LIST_VARIABLE - Configuration data packets - within node, list variables

	typedef struct		data_list_var_req_struct				// data request list variable structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						var_sub_type;						// HMI variable sub type
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
	} DATA_LIST_VAR_REQ_STR;

	typedef struct		data_list_var_struct						// data list variable structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						var_sub_type;						// HMI variable sub type
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
		uint_8						num_var;								// number of variables in list
		uint_8						reserved_2;							// reserved byte (alignment)
		uint_8						reserved_3;							// reserved byte (alignment)
		uint_8						reserved_4;							// reserved byte (alignment)
		DATA_VAR_STR				str_list[DEF_MAX_NUM_VARIABLE];	// variable list
	} DATA_LIST_VAR_STR;

	#define DATA_LIST_VAR_SIZE(x) 		(offsetof(DATA_LIST_VAR_STR, str_list) + (x * sizeof(DATA_VAR_STR)))


	// *** ENU_CMD_DATA_VARIABLE_EDIT_GET - Configuration data packets - variable edit (get contents before edit) 
	// *** ENU_CMD_DATA_VARIABLE_EDIT_SET - Configuration data packets - variable edit (set contents with edit value)

	typedef struct		data_var_edit_req_struct						// data request variable structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
		OBJECT_STR					str_var;								// variable object
	} DATA_VAR_EDIT_REQ_STR;

	typedef struct		data_var_edit_struct						// data variable structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
		OBJECT_STR					str_var;								// variable object
		uint_8						edit;									// edit style
		uint_8						attribute;							// attribute	
		uint_8						reserved_2;							// reserved byte (alignment)
		uint_8						reserved_3;							// reserved byte (alignment)
		DATA_VAR_UNI				uni_data;							// variable data union
	} DATA_VAR_EDIT_STR;


	// *** ENU_CMD_DATA_VARIABLE_LIST_COND - Configuration data packets - variable list conditional options

	typedef struct		data_list_var_cond_req_struct			// data request list variable conditional options structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
		OBJECT_STR					str_var;								// variable object
	} DATA_LIST_VAR_COND_REQ_STR;

	typedef struct		data_list_var_cond_struct				// data list var structure
	{
		uint_8						command;								// command code [DATA_CMD_ENU]
		uint_8						user_level;							// HMI user level
		uint_8						security_level;					// HMI security level
		uint_8						reserved_1;							// reserved byte (alignment)
		OBJECT_STR					str_group;							// group object
		OBJECT_STR					str_node;							// node object
		OBJECT_STR					str_var;								// variable object
		uint_8						num_cond;							// number of conditional objects in list
		uint_8						reserved_2;							// reserved byte (alignment)
		uint_8						reserved_3;							// reserved byte (alignment)
		uint_8						reserved_4;							// reserved byte (alignment)
		OBJECT_STR					str_list[DEF_MAX_NUM_OBJECT];	// conditional object list
	} DATA_LIST_VAR_COND_STR;
	
	#define DATA_LIST_VAR_COND_SIZE(x) 		(offsetof(DATA_LIST_VAR_COND_STR, str_list) + (x * sizeof(OBJECT_STR)))


	// *** ENU_CMD_DATA_LOCK_MODE - Hmi Lock Mode
	typedef struct		data_lock_mode_req_struct
	{
	    uint_8              command;								// command code [DATA_CMD_ENU]
	    uint_8              lock_mode;
	    uint_8					interface;
	    uint_8              reserved;
	} DATA_LOCK_MODE_REQ_STR;

	typedef struct		data_lock_mode_rsp_struct
	{
	    uint_8              command;								// command code [DATA_CMD_ENU]
	    uint_8              lock_mode;
	    uint_8					interface;
	    uint_8              response;
	} DATA_LOCK_MODE_RSP_STR;


		// *** Communications Payload - Data packets union	
		typedef union	payload_data_union
		{
			uint_8								command;
			DATA_LIST_GROUP_TYPE_REQ_STR	str_group_type_list_req;
			DATA_LIST_GROUP_TYPE_STR		str_group_type_list;
			DATA_LIST_GROUP_REQ_STR			str_group_list_req;
			DATA_LIST_GROUP_STR				str_group_list;
			DATA_GROUP_ADD_STR				str_group_add;
			DATA_LIST_NODE_REQ_STR			str_node_list_req;
			DATA_LIST_NODE_STR				str_node_list;
			DATA_LIST_NET_REQ_STR			str_net_list_req;
			DATA_LIST_NET_STR					str_net_list;
			DATA_NODE_LINK_REQ_STR			str_node_link_req;
			DATA_NODE_LINK_STR				str_node_link;
			DATA_LIST_NODE_ACTION_REQ_STR	str_node_action_list_req;
			DATA_LIST_NODE_ACTION_STR		str_node_action_list;
			DATA_NODE_ACTION_SET_STR		str_node_action_set;
			DATA_LIST_VAR_REQ_STR			str_var_list_req;
			DATA_LIST_VAR_STR					str_var_list;
			DATA_VAR_EDIT_REQ_STR			str_var_edit_req;
			DATA_VAR_EDIT_STR					str_var_edit;
			DATA_LIST_VAR_COND_REQ_STR		str_var_cond_list_req;
			DATA_LIST_VAR_COND_STR			str_var_cond_list;
			DATA_LOCK_MODE_REQ_STR			str_lock_mode_req;
			DATA_LOCK_MODE_RSP_STR			str_lock_mode_rsp;
         DATA_LIST_GROUP_ATTRIBUTE_REQ_STR   str_group_attribute_req;
         DATA_LIST_GROUP_ATTRIBUTE_STR       str_group_attribute;
	} PAYLOAD_DATA_UNI;


#endif // QUARTZ_COMM_DATA_STRUCTURES_H


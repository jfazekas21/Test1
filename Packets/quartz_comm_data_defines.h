/******************************************************************************
*				File:				quartz_comm_data_defines.h									*
*  			Description:	Communications Data Definitions							*
*           Copyright (c) 2013 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_DATA_DEFINES_H
#define QUARTZ_COMM_DATA_DEFINES_H

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

typedef enum								// data payload command codes
{
	ENU_CMD_DATA_UNDEF,						// undefined command code
	ENU_CMD_DATA_INVALID,					// interpreted packet was invalid (error response)
	ENU_CMD_DATA_LIST_TYPES,				// list all available types of groups
	ENU_CMD_DATA_LIST_GROUP,				// list all available groups of specified type (along with the revision level of the group)
	ENU_CMD_DATA_GROUP_LIST_NODE,			// within group, list nodes
	ENU_CMD_DATA_GROUP_LIST_NET,			// within group, list nets (and connections)
	ENU_CMD_DATA_NODE_GROUP_LINK,			// with node, indicate link to group
	ENU_CMD_DATA_NODE_LIST_ACTION,		// with node, list all actions (with data)
	ENU_CMD_DATA_NODE_SET_ACTION,			// set action for the node	
	ENU_CMD_DATA_NODE_LIST_ATTRIBUTE,	// within node, list all attribute variables (with data)
	ENU_CMD_DATA_NODE_LIST_VARIABLE,		// within node, list variables (with data)
	ENU_CMD_DATA_VARIABLE_EDIT_GET,		// variable edit (get contents before edit) 
	ENU_CMD_DATA_VARIABLE_EDIT_SET,		// variable edit (set contents with edit value)
	ENU_CMD_DATA_VARIABLE_LIST_COND,		// variable list conditional options
	ENU_CMD_DATA_EDIT_MODE,					// request for edit mode
	ENU_CMD_DATA_LOCK_MODE,					// lock mode
	ENU_CMD_DATA_GROUP_ADD,					// add group
	ENU_CMD_DATA_GROUP_ATTRIBUTE_REQ,	// group attribute list request
	ENU_CMD_DATA_GROUP_ATTRIBUTE,			// group attribute list
	ENU_CMD_DATA_MAX
} DATA_CMD_ENU;


typedef enum								// root index codes
{
	ENU_ROOT_INDEX_UNDEF,					// undefined root index
	ENU_ROOT_INDEX_START,					// starting root index (all additional roots will increment from this value)
	ENU_ROOT_INDEX_MAX = 0x255				// maximum root index
} ROOT_INDEX_ENU;	

typedef enum								// node data attributes
{
	ENU_ATTRIBUTE_NODE_UNDEF,				// undefined node attribute
	ENU_ATTRIBUTE_NODE_TITLE,				// node title attribute
	ENU_ATTRIBUTE_NODE_HEADER,				// node header attribute
	ENU_ATTRIBUTE_NODE_FOOTER,				// node footer attribute (multiples can exist)
	ENU_ATTRIBUTE_NODE_ICON_LEFT,			// icon attribute (aligned left, multiples can exist)
	ENU_ATTRIBUTE_NODE_ICON_RIGHT,		// icon attribute (aligned right, multiples can exist)
	ENU_ATTRIBUTE_NODE_MAX
} ATTRIBUTE_NODE_ENU;

typedef enum								// lock mode
{
	ENU_LOCK_MODE_UNDEF,
	ENU_LOCK_MODE_UNLOCKED,
	ENU_LOCK_MODE_SAVE,
	ENU_LOCK_MODE_CANCEL,
	ENU_LOCK_MODE_UNDO,
	ENU_LOCK_MODE_REDO,
	ENU_LOCK_MODE_MAX
} HMI_LOCK_MODE_ENU;

/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/


#endif // QUARTZ_COMM_DATA_DEFINES_H


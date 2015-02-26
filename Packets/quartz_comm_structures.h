/******************************************************************************
*				File:				quartz_comm_structures.h									*
*  			Description:	Communication Base Structures								*
*           Copyright (c) 2014 Cincinnati Test systems    		         		*
*         - Contains CONFIDENTIAL and TRADE SECRET information -          		*
******************************************************************************/

/*--------------------------------------------------------------------------*/
/*                            COMPILE FLAGS                                 */
/*--------------------------------------------------------------------------*/

#ifndef QUARTZ_COMM_STRUCTURES_H
#define QUARTZ_COMM_STRUCTURES_H

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


/*--------------------------------------------------------------------------*/
/*                            DEFINITIONS                                   */
/*--------------------------------------------------------------------------*/

typedef struct		object_struct						// object structure 
{
	uint_16						type;							// object type	
	uint_16						code;							// object code
	uint_16						num;							// object number
	uint_8						reserved_1;					// reserved byte (alignment)
	uint_8						reserved_2;					// reserved byte (alignment)
} OBJECT_STR;

typedef struct		variable_integer_struct			// data variable integer structure 
{
	OBJECT_STR					str_unit;					// unit object
	uint_32						u32_data;					// integer data					
} VARIABLE_INT_STR;	

typedef struct		variable_int_arr_struct			// variable integer array structure 
{
	OBJECT_STR					str_unit;					// unit object
	uint_8						num_var;						// number of variables
	uint_8						reserved_1;					// reserved byte (alignment)
	uint_8						reserved_2;					// reserved byte (alignment)
	uint_8						reserved_3;					// reserved byte (alignment)
	uint_32						u32_array[DEF_MAX_NUM_VARIABLE_ARRAY];	// integer data					
} VARIABLE_INT_ARR_STR;		
				
typedef struct		variable_float_struct			// variable float structure 
{
	OBJECT_STR					str_unit;					// unit object	
	uint_8						precision;					// variable precision
	uint_8						reserved_1;					// reserved byte (alignment)
	uint_8						reserved_2;					// reserved byte (alignment)
	uint_8						reserved_3;					// reserved byte (alignment)
	float							fl_data;						// float data
} VARIABLE_FLOAT_STR;		

typedef struct		variable_float_arr_struct		// variable float structure 
{
	OBJECT_STR					str_unit;					// unit object	
	uint_8						precision;					// variable precision
	uint_8						num_var;						// number of variables
	uint_8						reserved_1;					// reserved byte (alignment)
	uint_8						reserved_2;					// reserved byte (alignment)
	float							fl_array[DEF_MAX_NUM_VARIABLE_ARRAY];		// float data
} VARIABLE_FLOAT_ARR_STR;		

typedef struct		variable_double_struct			// variable double structure 
{
	OBJECT_STR					str_unit;					// unit object	
	uint_8						precision;					// variable precision
	uint_8						reserved_1;					// reserved byte (alignment)
	uint_8						reserved_2;					// reserved byte (alignment)
	uint_8						reserved_3;					// reserved byte (alignment)
	double						db_data;						// double data		
} VARIABLE_DOUBLE_STR;	

typedef struct		variable_ascii_struct			// variable ascii structure 
{
	uint_8						length;						// ascii string length
	uint_8						data[DEF_MAX_LEN_ASCII_VARIABLE];	// ascii string
} VARIABLE_ASCII_STR;	

typedef union		communication_variable_content_union		// communications variable contents union
{
	VARIABLE_INT_STR			str_int;
	VARIABLE_INT_ARR_STR		str_int_arr;
	VARIABLE_FLOAT_STR		str_float;
	VARIABLE_FLOAT_ARR_STR	str_float_arr;
	VARIABLE_DOUBLE_STR		str_double;
	OBJECT_STR					str_cond;
	VARIABLE_ASCII_STR		str_ascii;
} COMM_VAR_UNI;	



#endif // QUARTZ_COMM_STRUCTURES_H


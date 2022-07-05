/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stddef.h>
#include <stdint.h>
/**
* @brief Move data from src to dest.
*
* Given a source pointer, a destination pointer, and a byte length,
* move the byte length of data from the source pointer to the destination 
* pointer.
* 
* @param src Pointer to source data array
* @param dst Pointer to destination data array
* @param length Length of data to move, in bytes.
* 
* @return Destination pointer.
*/
uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length);

/**
* @brief Copy data from src to dest.
*
* Given a source pointer, a destination pointer, and a byte length,
* copy the byte length of data from the source pointer to the destination 
* pointer.
* 
* @param src Pointer to source data array
* @param dst Pointer to destination data array
* @param length Length of data to copy, in bytes.
* 
* @return Destination pointer.
*/
uint8_t* my_memcopy(uint8_t* src, uint8_t* dst, size_t length);

/**
* @brief Set data in src to value.
*
* Given a source pointer, a byte length, and a set value,
* set the byte length of data in the source pointer to the set value.
* 
* @param src Pointer to source data array
* @param length Length of data to set, in bytes.
* @param value Value to set memory to.
* 
* @return Source pointer.
*/
uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value);

/**
* @brief Set data in src to 0.
*
* Given a source pointer and  a byte length,
* set the byte length of data in the source pointer to 0.
* 
* @param src Pointer to source data array
* @param length Length of data to set, in bytes.
* 
* @return Source pointer.
*/
uint8_t* my_memzero(uint8_t* src, size_t length);

/**
* @brief Reverse the order of bytes.
*
* Given a source pointer and  a byte length,
* reverse the order of the byte length of data in the source pointe.
* 
* @param src Pointer to source data array
* @param length Length of data to reverse order of, in bytes.
* 
* @return Source pointer.
*/
uint8_t* my_reverse(uint8_t* src, size_t length);

/**
* @brief Reserve this number of bytes.
*
* Given a byte length, reserve this number of bytes in dynamic memory.
* 
* @param length Length of data to reserve, in bytes.
* 
* @return If successful, pointer to memory created. Else, NULL.
*/
int32_t* reserve_words(size_t length);

/**
* @brief Free dynamic memory.
*
* Given a source pointer, free this dynamic memory.
* 
* @param src Pointer to source data array.
* 
* @return void.
*/
void free_words(uint32_t* src);

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

#endif /* __MEMORY_H__ */
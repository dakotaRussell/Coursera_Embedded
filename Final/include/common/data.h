/**
* @file data.h
* @brief Abstraction of type conversion operations
* 
* This header file provides an abstraction of converting integers to ascii
* and ascii to integers.
*
* @author Dakota Russell
* @date 06/28/2022
*/

#ifndef __DATA_H__
#define __DATA_H__

/**
* @brief Convert data from int to ASCII string.
*
* Given an integer, a byte pointer, and a base,
* convert the integer to the base requested, writing the result as an ASCII
* string to the byte pointer.
*
* @param data 32 bit integer to convert.
* @param ptr 8 bit pointer to write ASCII string to.
* @param base Base to convert to, 2 to 16 supported.
*
* @return Length of converted data, including sign and null terminator.
*/
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);

/**
* @brief Convert data from an ASCII string to integer.
*
* Given a byte pointer, number of digits, and a base,
* convert the ASCII string contained in the byte pointer to the base requested.
* 
* @param ptr 8 bit pointer containing ASCII string to convert.
* @param digits Number of digits contained in character set.
* @param base Base to convert to, 2 to 16 supported.
* 
* @return Converted 32-bit signed integer.
*/
int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);

#endif

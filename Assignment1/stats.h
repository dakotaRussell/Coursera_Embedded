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
 * @file stats.h 
 * @brief Calculate statistics for unsigned char data. 
 *
 * Provided an input array of unsigned char data, this file sorts the input array
 * largest to smallest before calculating the following statistics:
 * 1. minimum,
 * 2. maximum, 
 * 3. median,
 * 4. mean.
 * The statistic value returned is rounded down to the nearest integer.
 *
 * @author Dakota Russell
 * @date 06/10/2022
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

unsigned char find_maximum(unsigned char* array, int length);
unsigned char find_mean(unsigned char* array, int length);
unsigned char find_median(unsigned char* array, int length);
unsigned char find_minimum(unsigned char* array, int length);
unsigned char print_array(unsigned char* array, int length);
unsigned char print_statistics(unsigned char* array, int length);
unsigned char sort_array(unsigned char* array, int length);

#endif

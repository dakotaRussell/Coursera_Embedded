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

/* @brief Find Maximum of Dataset.
 *
 * Find maximum value of dataset.
 *
 * @param array Input array to find maximum of.
 * @param length Length of input array.
 *
 * @return Maximum value of dataset.
 */
unsigned char find_maximum(unsigned char[] array, int length);

/* @brief Find Mean of Dataset.
 *
 * Find mean value of dataset. Round mean down to nearest integer.
 *
 * @param array Input array to find mean of.
 * @param length Length of input array.
 *
 * @return Mean value of dataset as integer.
 */
unsigned char find_mean(unsigned char[] array, int length);

/* @brief Find Median of Dataset.
 *
 * Find median value of dataset.
 *
 * @param array Input array to find median of.
 * @param length Length of input array.
 *
 * @return Median value of dataset.
 */
unsigned char find_median(unsigned char[] array, int length);

/* @brief Find Minimum of Dataset.
 *
 * Find minimum value of dataset.
 *
 * @param array Input array to find minimum of.
 * @param length Length of input array.
 *
 * @return Minimum value of dataset.
 */
unsigned char find_minimum(unsigned char[] array, int length);

/* @brief Print array.
 *
 * Print array values to screen.
 *
 * @param array Input array to print.
 * @param length Length of input array.
 *
 * @return void.
 */
void print_array(unsigned char[] array, int length);

/* @brief Print statistics.
 *
 * Print provided statistics in a formatted manner to screen.
 *
 * @param minimum Dataset minimum as integer.
 * @param maximum Dataset maximum as integer.
 * @param median Dataset median as integer.
 * @param mean Dataset mean as integer.
 *
 * @return void.
 */
void print_statistics(unsigned char minimum, unsigned char maximum, 
		unsigned char median, unsigned char mean);

/* @brief Sort array.
 *
 * Sort input array from largest to smallest in-place.
 *
 * @param array Input array to sort.
 * @param length Length of input array.
 *
 * @return void.
 */
void sort_array(unsigned char[] array, int length);

#endif

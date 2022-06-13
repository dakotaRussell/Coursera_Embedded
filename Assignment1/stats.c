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
 * @file stats.c 
 * @brief Statistic calculator.
 *
 * Given input data array, sort largest to smallest before calculating the
 * following statistics:
 * 1. minimum
 * 2. maximum
 * 3. median
 * 4. mean.
 * Each returned statistic is rounded down to the nearest integer. Sorted array and
 * statistics are printed in a formatted style.
 *
 * @author Dakota Russell
 * @date 06/10/2022
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  sort_array(test, SIZE);
  unsigned char minimum = find_minimum(test, SIZE);
  unsigned char maximum = find_maximum(test, SIZE);
  unsigned char median = find_median(test, SIZE);
  unsigned char mean = find_mean(test, SIZE);

  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  print_statistics(minimum, maximum, median, mean);

}

/* Add other Implementation File Code Here */
unsigned char find_maximum(unsigned char[] array, int length){
  if (array == NULL) return 0;
  unsigned char maximum = array[0];
  for (int i=0; i<length; i++){
    if (array[i] > maximum)
	  maximum = array[i];  
  }
  return maximum;
}

unsigned char find_mean(unsigned char[] array, int length){
  if (array == NULL) return 0;
  unsigned int sum = 0;
  for (int i=0; i<length; i++){
    sum += array[i];
  }
  return (unsigned char)(sum/length);
}

unsigned char find_median(unsigned char[] array, int length){
  if (array == NULL) return 0;
  // Cannot assume input array was sorted.
  sort_array(array, length);
  return array[length/2];
}

unsigned char find_minimum(unsigned char[] array, int length){
  if (array == NULL) return 0;
  unsigned char minimum = array[0];
  for (int i=0; i<length; i++){
    if (array[i] < minimum)
	  minimum = array[i];  
  }
  return minimum;
}

void print_array(unsigned char[] array, int length){
  if (array == NULL || length == 0) return;
  for (int i=0; i<length-1; i++){
    printf("%d, ", array[i]);
  }
  printf("%d", array[length-1]);
  return;
}

void print_statistics(unsigned char minimum, unsigned char maximum, 
		unsigned char median, unsigned char mean){
  printf("Minimum:\t%d,\n", minimum);
  printf("Maximum:\t%d,\n", maximum);
  printf("Median:\t%d,\n", median);
  printf("Mean:\t%d.\n", mean);
  return;
}

static void swap(unsigned char* x, unsigned char* y){
  unsigned char tmp = *x;
  *x = *y;
  *y = tmp;
}

static int partition(unsigned char[] array, int left, int right, int pivot){
  while (left <= right){
    while (array[left] > pivot) left++;
    while (array[right] < pivot) right--;

    swap(&array[left], &array[right]);
  }
  return left;
}

static void sort_array(unsigned char[] array, int left, int right){
  if (left >= right) return;

  int pivot = (left + right)/2;
  int partition = partition(array, left, right, array[pivot]);
  sort_array(array, left, partition-1);
  sort_array(array, partition+1, right);
  return;
}

void sort_array(unsigned char[] array, int length){
  if (array == NULL || length == 0) return;
  sort_array(array, 0, length-1);
  return;
}

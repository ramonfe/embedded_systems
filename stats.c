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
 * @file <stats.c> 
 * @brief < A file that covers the first ssignment for Embedded System course >
 *
 * <Add Extended Description Here>
 *
 * @author <Ramon Felix>
 * @date <Nov 14, 2019>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
unsigned char find_mean(unsigned char * ptr, unsigned int count) {
	int i;
	int mean = 0;

	for (i = 0; i < count; i++) {
		mean += *ptr;
		ptr++;
	}

	return (mean / count);
}
unsigned char find_median(unsigned char * ptr, unsigned int count) {
	int i = 0;
	int median = 0;
	i = count / 2;
	if (count % 2 == 0)
	{
		median = (ptr[i] + ptr[i + 1]) / 2;
	}
	else
	{
		median = ptr[i];
	}
	return median;
}
void sort_array(unsigned char  * ptr, unsigned int count) {
	int i, j, max, temp;
	for (i = 0; i < count - 1; i++) {
		max = i;
		for (j = i + 1; j < count; j++)
			if (ptr[j] > ptr[max])
				max = j;
		temp = ptr[i];
		ptr[i] = ptr[max];
		ptr[max] = temp;
	}
}
unsigned char find_maximum(unsigned char * ptr, unsigned int count) {
	int i, j, max, temp;
	max = 0;
	for (i = 0; i < count - 1; i++) {
		if (ptr[i + 1] > ptr[max])
			max = i + 1;
	}
	return ptr[max];
}
void print_array(unsigned char * ptr, unsigned int count) {
  int i=0;	
  for (i = 0; i < count; i++)
	printf(", %d", ptr[i]);
}
unsigned char find_minimum(unsigned char * ptr, unsigned int count) {
	int i, j, min, temp;
	min = 0;
	for (i = 0; i < count - 1; i++) {
		if (ptr[i + 1] < ptr[min])
			min = i + 1;
	}
	return ptr[min];
}
void print_statistics(unsigned char * ptr, unsigned int count) {
	printf("\nGiven Array is: \n");
	print_array(ptr, count);
	printf("\nSorted Array is: \n");
	sort_array(ptr, count);
	print_array(ptr, count);
	printf("\nMin Array Value is: %d \n", find_minimum(ptr, count));
	printf("\nMax Array Value is: %d \n", find_maximum(ptr, count));
	printf("\nMean Array Value is: %d \n", find_mean(ptr, count));
	printf("\nMedian Array Value is: %d \n", find_median(ptr, count));
}
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  unsigned int n = sizeof(test) / sizeof(test[0]);
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, n);
}

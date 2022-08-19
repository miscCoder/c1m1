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
 * @brief header for stats.c
 *
 * used to 
 *
 * @author Victor Iseli
 * @date 2022, Aug 18
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/******************************************************************************
 * @brief Function: print_statistics
 * Description: 
 *    A function that prints the statistics of an array including minimum, maximum, mean, and median.
 * 
 * Parameters:
 * @param unsigned char *array    - array to be analyzed, and printed
 * @param unsigned int arraySize  - array size
 * 
 * Return:
 * @return int                     - error code, zero if success
 *
 *****************************************************************************/
int print_statistics( unsigned char *array, unsigned int arraySize);

/******************************************************************************
 * @brief Function: print_array
 * Description: 
 *    Given an array of data and a length, prints the array to the screen
 * 
 * Parameters:
 * @param unsigned char *array    - array to print
 * @param unsigned int arraySize  - array size
 * 
 * Return:
 * @return int                     - error code, zero if success
 *
 *****************************************************************************/
int print_array( unsigned char *array, unsigned int arraySize);

/******************************************************************************
 * @brief Function: find_median
 * Description: 
 *    Given an array of data and a length, returns the median value
 *    This will sort the array first, so the by-product is that the array
 *    remains sorted - if this is not desired, a copy of the original array
 *    should be passed
 * 
 * Parameters:
 * @param unsigned char *array    - array to analyze
 * @param unsigned int arraySize  - array size
 * @param unsigned char *median   - returns calculated median, pass by reference
 * 
 * Return:
 * @return int                     - error code, zero if success
 *
 *****************************************************************************/
int find_median( unsigned char *array, unsigned int arraySize, unsigned char *median);

/******************************************************************************
 * @brief Function: find_mean
 * Description: 
 *    Given an array of data and a length, returns the mean
 * 
 * Parameters:
 * @param unsigned char *array    - array to analyze
 * @param unsigned int arraySize  - array size
 * @param unsigned char *mean     - returns calculated mean, pass by reference
 * 
 * Return:
 * @return int                     - error code, zero if success
 *
 *****************************************************************************/
int find_mean( unsigned char *array, unsigned int arraySize, unsigned char *mean);

/******************************************************************************
 * @brief Function: find_maximum
 * Description: 
 *    Given an array of data and a length, returns the maximum
 * 
 * Parameters:
 * @param unsigned char *array    - array to analyze
 * @param unsigned int arraySize  - array size
 * @param unsigned char *mean     - returns calculated maximum, pass by reference
 * 
 * Return:
 * @return int                     - error code, zero if success
 *
 *****************************************************************************/
int find_maximum( unsigned char *array, unsigned int arraySize, unsigned char *maximum);

/******************************************************************************
 * @brief Function: find_minimum
 * Description: 
 *    Given an array of data and a length, returns the minimum
 * 
 * Parameters:
 * @param unsigned char *array    - array to analyze
 * @param unsigned int arraySize  - array size
 * @param unsigned char *mean     - returns calculated minimum, pass by reference
 * 
 * Return:
 * @return int                     - error code, zero if success
 *
 *****************************************************************************/
int find_minimum( unsigned char *array, unsigned int arraySize, unsigned char *minimum);

/******************************************************************************
 * @brief Function: sort_array
 * Description: 
 *    Given an array of data and a length, sorts the array from largest to 
 *    smallest.  (The zeroth element should be the largest value, and the last 
 *    element (n-1) should be the smallest value. )
 * 
 * Parameters:
 * @param unsigned char *array    - array to be sorted (this will be modified by the sort)
 * @param unsigned int arraySize  - array size
 * 
 * Return:
 * @return int                     - error code, zero if success
 *
 *****************************************************************************/
int sort_array( unsigned char *array, unsigned int arraySize);

#endif /* __STATS_H__ */

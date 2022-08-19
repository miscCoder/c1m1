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
 * @brief assignment 1 for Intro to Embedded Systems Software and Development Environments
 *
 * analyze an array of unsigned char data items and report analytics on the maximum, minimum,
 * mean, and median of the data set. In addition, you will need to reorder this data set from large to small
 *
 * @author Victor Iseli
 * @date 2022, Aug 18
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

#define ERROR_ZERO_LENGTH_ARRAY 1
#define ERROR_OK                0

/******************************************************************************
 * Function: main
 * Description:
 *
 * Parameters:
 * Return:
 *
 *****************************************************************************/
int main( ) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int error = ERROR_OK;

  /* Statistics and Printing Functions Go Here */
  printf( "original array:\r\n");
  error = print_array( test, SIZE);
  if( error) printf( "error after print_array %d\r\n", error);

  error = print_statistics( test, SIZE);
  if( error) printf( "error after print_array %d\r\n", error);

  printf( "sorted array:\r\n");
  error = print_array( test, SIZE);
  if( error) printf( "error after print_array %d\r\n", error);

  return 0;
}

/* Add other Implementation File Code Here */

/***** FUNCTIONS *****/

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
int print_statistics( unsigned char *array, unsigned int arraySize)
{
  int error = 0;
  unsigned char arrayMin = 0, arrayMax = 0, arrayMean = 0, arrayMedian = 0;

  if( ( error = find_minimum( array, arraySize, &arrayMin)) != ERROR_OK)
  {
    printf( "error %d getting minimum\r\n", error);
  }
  else printf( "minimum = %d\r\n", arrayMin);

  if( ( error = find_maximum( array, arraySize, &arrayMax)) != ERROR_OK)
  {
    printf( "error %d getting maximum\r\n", error);
  }
  else printf( "maximum = %d\r\n", arrayMax);

  if( ( error = find_mean( array, arraySize, &arrayMean)) != ERROR_OK)
  {
    printf( "error %d getting mean\r\n", error);
  }
  else printf( "mean = %d\r\n", arrayMean);

  if( ( error = find_median( array, arraySize, &arrayMedian)) != ERROR_OK)
  {
    printf( "error %d getting median\r\n", error);
  }
  else printf( "median = %d\r\n", arrayMedian);

  return error;
}

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
int print_array( unsigned char *array, unsigned int arraySize)
{
  int error = 0;
  unsigned int arrayIndex;
  const int kColumns = 10;

  printf( "length = %d\r\n", arraySize);
  printf( "[ \r\n");
  for( arrayIndex = 0; arrayIndex < arraySize; ++arrayIndex)
  {
    printf( " %3d", array[arrayIndex]);
    if( !((arrayIndex + 1) % kColumns) && ( ( arrayIndex + 1) < arraySize))
      printf( "\r\n");
    else if( ( arrayIndex + 1) < arraySize)
      printf( ",");
  }
  printf( "\r\n] \r\n");

  return error;
}

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
int find_median( unsigned char *array, unsigned int arraySize, unsigned char *median)
{
  int error = 0;
  unsigned int arrayMiddle = 0;

  if( arraySize <= 0) return ERROR_ZERO_LENGTH_ARRAY;

  error = sort_array( array, arraySize);
  arrayMiddle = ( arraySize + 1) / 2 - 1; // it is necessary to subtract one, due to array indices 0-(n-1)
  if( arraySize % 2)
  { // for odd number of elements, just the middle one
    *median = array[arrayMiddle];
  }
  else
  { // for even number of elements, it is the average of the two middle ones
    *median = ( array[arrayMiddle] + array[arrayMiddle + 1]) / 2;
  }

  return error;
}

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
int find_mean( unsigned char *array, unsigned int arraySize, unsigned char *mean)
{
  int error = 0;
  unsigned int arrayIndex;
  unsigned int accumulation = 0;

  *mean = 0;

  if( arraySize <= 0) return ERROR_ZERO_LENGTH_ARRAY;

  for( arrayIndex = 0; arrayIndex < arraySize; ++arrayIndex)
  {
    accumulation += array[arrayIndex];
  }
  *mean = accumulation / arraySize; // note this is an integer division

  return error;
}

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
int find_maximum( unsigned char *array, unsigned int arraySize, unsigned char *maximum)
{
  int error = 0;
  unsigned int arrayIndex;

  *maximum = 0;

  if( arraySize <= 0) return ERROR_ZERO_LENGTH_ARRAY;

  for( arrayIndex = 0; arrayIndex < arraySize; ++arrayIndex)
  {
    if( array[arrayIndex] > *maximum)
      *maximum = array[arrayIndex];
  }

  return error;
}

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
int find_minimum( unsigned char *array, unsigned int arraySize, unsigned char *minimum)
{
  int error = 0;
  unsigned int arrayIndex;

  *minimum = 0xff;

  if( arraySize <= 0) return ERROR_ZERO_LENGTH_ARRAY;

  for( arrayIndex = 0; arrayIndex < arraySize; ++arrayIndex)
  {
    if( array[arrayIndex] < *minimum)
      *minimum = array[arrayIndex];
  }

  return error;
}

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
int sort_array( unsigned char *array, unsigned int arraySize)
{
  int error = ERROR_OK;
  unsigned int arrayIndex = 0;
  unsigned char thisElement, nextElement;

  if( arraySize <= 0) return ERROR_ZERO_LENGTH_ARRAY;
  if( arraySize <= 1) return ERROR_OK;

  // scans through array starting at beginnging (zeroth) element, looking for a<b condition
  // if reordering, then it will backup till condition is met
  while( (arrayIndex + 1) <= arraySize - 1)
  {
    thisElement = array[arrayIndex];
    nextElement = array[arrayIndex + 1];
    if( thisElement >= nextElement) arrayIndex++;
    else
    {
      array[arrayIndex] = nextElement;
      array[arrayIndex + 1] = thisElement;
      if( arrayIndex > 0)
      {
        arrayIndex--;
      }
    }
  }

  return error;
}

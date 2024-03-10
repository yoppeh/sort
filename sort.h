/**
 * @file sort.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief Implementations of various sorting algorithms.
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef _SORT_H
#define _SORT_H

/**
 * @brief Bubble sort implementation.
 * 
 * @param a array of integers to sort
 * @param n number of elements in array a
 */
extern void sort_bubble(int *a, int n);

/**
 * @brief Heap sort implementation.
 * 
 * @param a array of integers to sort
 * @param n number of elements in array a
 */
extern void sort_heap(int *a, int n);

/**
 * @brief Insertion sort implementation.
 * 
 * @param a array of integers to sort
 * @param n number of elements in array a
 */
extern void sort_insertion(int *a, int n);

/**
 * @brief Merge sort implementation.
 * 
 * @param a array of integers to sort
 * @param n number of elements in array a
 */
extern void sort_merge(int *a, int n);

/**
 * @brief Quick sort implementation.
 * 
 * @param a array of integers to sort
 * @param n number of elements in array a
 */
extern void sort_quick(int *a, int n);

#endif // _SORT_H
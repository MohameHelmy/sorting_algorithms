#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

int getMagnitude(int n);
char *convertToStr(int n);
void _putNum(int n);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap(int *x, int *y);
void print_arr(const int *array, size_t size);
void _putchar(char c);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recur(int *array, int low, int high, size_t size);
int partition_lomuto(int arr[], int low, int high,  size_t size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort_hoare_recur(int *array, int low, int high, size_t size);
int partition_hoare(int arr[], int low, int high,  size_t size);
void merge_sort(int *array, size_t size);
void CopyArray(int A[], int iBegin, int iEnd, int B[]);
void TopDownMerge(int B[], int iBegin, int iMiddle, int iEnd, int A[]);
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[]);
void merge_sort_recur(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);
#endif

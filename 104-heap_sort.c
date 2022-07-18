#include "sort.h"

/**
 * swap - swaps position of values in array
 * @array: array to be changed
 * @first: first index
 * @second: second index
 *
 * Return: nothing
 */
void swap(int **array, size_t first, size_t second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * build_Max_Heap - builds a heap from an array
 * @array: array to be changed to heap array
 * @i: index of array element
 *
 * Return: array as sorted heap 
 */
void build_Max_Heap(int *array, size_t i, size_t size)
{
	size_t largest, left, right;

	largest = i;
	left = i * 2;
	right = (i * 2) + 1;

	/*printf("")*/
	while (left <= size && array[left] > array[largest])
		largest = left;

	while (right <= size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array, largest, i);
		build_Max_Heap(array, largest, size);
		print_array(array, size);
	}
}

/**
 * heap_sort - sorts an array using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t start_index, i;

	start_index = size / 2;

	/*Build max heap*/
	for (i = start_index - 1; i >= 0; i--)
		build_Max_Heap(array, start_index, size);

	/*Destroy max heap*/
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array, 1, i);
		build_Max_Heap(array, 1, size);
	}
}

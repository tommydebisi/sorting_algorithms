#include "sort.h"

/**
 * swap - swaps position of values in array
 * @array: array to be changed
 * @first: first index
 * @second: second index
 *
 * Return: nothing
 */
void swap(int **array, int first, int second)
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
void build_Max_Heap(int *array, int size, int start_index, int a_size)
{
	int largest, left, right;

	largest = start_index;
	left = (start_index * 2) + 1;
	right = (start_index * 2) + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != start_index)
	{
		swap(&array, start_index, largest);
		print_array(array, a_size);
		build_Max_Heap(array, size, largest, a_size);
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
	int start_index, i;

	if (!array || size < 2)
		return;

	start_index = ((int)size - 1) / 2;

	/*Build max heap*/
	for (i = start_index; i >= 0; i--)
	{
		build_Max_Heap(array, size, i, size);
	}

	/*Destroy max heap*/
	for (i = size - 1; i >=0; i--)
	{
		swap(&array, 0, i);
		print_array(array, size);
		build_Max_Heap(array, i, 0, size);
	}
}

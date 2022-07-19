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
void build_Max_Heap(int *array, int i, size_t size)
{
	int largest, left, right;

	largest = i;
	left = (i * 2) + 1;
	right = (i * 2) + 2;

	/*printf("")*/
	if (left <= (int)size && array[left] > array[largest])
	{
		printf("before \n");
		printf("size = %i left = %i largest = %i\n", (int)size, left, largest);
		printf("array[%i] = %i\n", left, array[left]);
		printf("array[%i] = %i\n", largest, array[largest]);
		largest = left;
		printf("after \n");
		printf("size = %i left = %i largest = %i\n", (int)size, left, largest);
		printf("array[%i] = %i\n", left, array[left]);
		printf("array[%i] = %i\n", largest, array[largest]);

	}

	if (right <= (int)size && array[right] > array[largest])
	{
		printf("before \n");
		printf("size = %i right = %i largest = %i\n", (int)size, right, largest);
		printf("array[%i] = %i\n", right, array[right]);
		printf("array[%i] = %i\n", largest, array[largest]);
		largest = right;
		printf("after \n");
		printf("size = %i right = %i largest = %i\n", (int)size, right, largest);
		printf("array[%i] = %i\n", right, array[right]);
		printf("array[%i] = %i\n", largest, array[largest]);

	}

	if (largest != i)
	{
		swap(&array, largest, i);
		print_array(array, size);
		build_Max_Heap(array, largest, size);
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

	start_index = (size / 2) - 1;
	size = size - 1;

	/*Build max heap*/
	for (i = start_index; i >= 0; i--)
	{
		/*printf("size = %i i = %i", (int)size, i);*/
		build_Max_Heap(array, i, size);
	}

	/*Destroy max heap*/
	/*for (i = size; i >= 0; i--)
	{
		swap(&array, 0, i);
		build_Max_Heap(array, 0, size);
	}*/
}

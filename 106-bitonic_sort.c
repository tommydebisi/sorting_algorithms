#include "sort.h"

/**
 * swap_pos - swaps position of values in array
 *
 * @array: array to be changed
 * @first: first index
 * @second: second index
 */
void swap_pos(int *array, size_t first, size_t second)
{
	int holder;

	holder = (array)[first];
	(array)[first] = (array)[second];
	(array)[second] = holder;
}

/**
 * infoMerge - prints the current status of merging or
 * end result
 *
 * @arr: array to be printed
 * @lb: index to start from
 * @ub: size of the sub array
 * @s: current status of the function
 * @size: size of main array to be sorted
 * @order: increasing or decreasing order
 */
void infoMerge(int *arr, size_t lb, size_t ub, char *s, size_t size, int order)
{
	size_t i;
	char *seperator = "";

	if (order)
		printf("%s [%d/%d] (UP):\n", s, (int)ub, (int)size);
	else
		printf("%s [%d/%d] (DOWN):\n", s, (int)ub, (int)size);

	for (i = lb; i < ub; i++)
	{
		printf("%s%d", seperator, arr[i]);
		seperator = ", ";
	}
	printf("\n");
}

/**
 * merger - merges the array according to increasing or
 * decreasing order
 *
 * @arr: array to be sorted
 * @lb: starting index of sub array
 * @ub: size of sub array
 * @order: increasing or decreasing order
 * @size: size of main array
 */
void merger(int *arr, size_t lb, size_t ub, int order, size_t size)
{
	size_t flag = 0, middle, lStart = lb;

	if (ub <= 1)
		return;

	middle = (ub - lb) / 2;

	while (lStart < middle)
	{
		/* loop through and swap with a gap of low + middle */
		if (order == (arr[lStart] > arr[lStart + middle]))
		{
			swap_pos(arr, lStart, lStart + middle);
			flag = 1;
		}
	}
	
	if (flag)
		infoMerge(arr, lb, ub, "Result", size, order);
	merger(arr, lb, middle, order, size);
	merger(arr, lb + middle, middle, order, size);
}

/**
 * bSequence - bitonic sequence splits the array in group of
 * increasing or decreasing order and sorts the array finally
 *
 * @array: array to be sorted
 * @lb: lower bound
 * @ub: upper bound
 * @order: decreasing (0) or increasing (1) order
 * @size: size of main array
 */
void bSequence(int *array, size_t lb, size_t ub, int order, size_t size)
{
	size_t mid;

	if (ub > 1)
	{

		infoMerge(array, lb, ub, "Merging", size, order);
		printf("%ld\n", ub);
		mid = ub / 2;
		printf("mid %ld\n", mid);
		printf("low: %ld\n", lb);

		bSequence(array, lb, mid, 1, size);
		printf("here");
		bSequence(array, mid + lb, mid, 0, size);
		merger(array, lb, ub, order, size);
	}
}

/**
 * bitonic_sort - implementation of the bitonic sort algorithm
 * to sort an array with size which is a power of 2
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bSequence(array, 0, size, 1, size);
}

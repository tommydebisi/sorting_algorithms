#include "sort.h"

/**
 * arr_zero_init - initialize array by 0
 *
 * @array: array to be initialized
 * @size: size of the array
 */
void arr_zero_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * get_max - gets the maximum value in the array
 *
 * @array: array to get max value from
 * @size: size of the array
 *
 * Return: maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	if (size < 2)
		return (0);

	max = array[0];	/* start from first index */

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 * sort_counter - sorts an array using the counting_sort
 * algorithm for LSD radix sort algorithm
 *
 * @array: initial array
 * @size: size of the array
 * @place: position of the LSD (least significant digit)
 */
void sort_counter(int *array, size_t size, int place)
{
	int k, *position, *sumPosition, *sorted;
	size_t i, j;

	position = malloc(sizeof(int) * size);
	if (!position)
		return;
	arr_zero_init(position, size);

	for (i = 0; i < size; i++)
		position[(array[i] / place) % 10] += 1;    /* position at LSD */

	sumPosition = malloc(sizeof(int) * size);
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, size);
	sumPosition[0] = position[0];   /* make first index equal */

	for (j = 1; j < size; j++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (k = size - 1; k >= 0; k--)  /* get the sorted array */
	{
		sumPosition[(array[k] / place) % 10] -= 1;
		sorted[sumPosition[(array[k] / place) % 10]] = array[k];
	}
	free(sumPosition);

	for (i = 0; i < size; i++)  /* update array */
		array[i] = sorted[i];
	free(sorted);
}

/**
 * radix_sort - peforms the the LSD (least significant Digit)
 * radix sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size), position = 1;

	if (!array || size < 2)
		return;

	while ((max / position) > 0)
	{
		sort_counter(array, size, position);
		print_array(array, size);
		position *= 10;
	}
}

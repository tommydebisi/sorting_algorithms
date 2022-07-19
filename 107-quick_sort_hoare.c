#include "sort.h"

/**
 * swap_pos - swaps position of values in array
 *
 * @array: array to be changed
 * @first: first index
 * @second: second index
 */
void swap_pos(int **array, size_t first, size_t second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * partition - splits the array into two parts
 * part lower than the sorted index and a part higher
 *
 * @array: array to be sorted
 * @lower: lower boundary
 * @upper: upper boundary
 * @size: size of the array
 *
 * Return: index of sorted pivot
 */
size_t partition(int *array, size_t lower, size_t upper, size_t size)
{
	int before, after, pivot;

	pivot = (int)upper;
    before = (int)lower;
    after = pivot;  /* end before the last index */

	while (before < after)
	{
        while (array[before] <= array[pivot])
            before++;

        while (array[after] > array[pivot])
            after--;

        if (before < after)
        {
            swap_pos(&array, before, after);
            printf("after: %d\n", after);
            if (after == pivot)
                pivot = after;
            print_array(array, size);
        }
	}

	/* swap pivot to its original position */
	if (before > after)
	{
		swap_pos(&array, before, pivot);
		print_array(array, size);
	}
	return (before);
}

/**
 * sorter - recursively sorts the array given
 *
 * @array: array to be sorted
 * @lb: lower bound
 * @ub: upper bound
 * @size: size of the array
 */
void sorter(int *array, size_t lb, size_t ub, size_t size)
{
	size_t sorted_index;

	/* recursive breakpoint */
	if (lb < ub && array)
	{
		sorted_index = partition(array, lb, ub, size);

		/* perform recursive sort */
		if (sorted_index - lb > 1)	/* more than one element must be present */
			sorter(array, lb, sorted_index - 1, size);    /* sort lower boundary */

		if (ub - sorted_index > 1)
			sorter(array, sorted_index + 1, ub, size);    /* sort upper boundary */
	}
}

/**
 * quick_sort_hoare - implements the quick sort algo using
 * hoare partition scheme
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	/* create the sorter function to recursively sort the array */
	sorter(array, 0, size - 1, size);
}
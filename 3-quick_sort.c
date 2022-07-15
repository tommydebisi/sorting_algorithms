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
 *
 * Return: index of sorted pivot
 */
size_t partition(int **array, size_t lower, size_t upper)
{
	size_t before, after, pivot;

	pivot = upper;
	before = lower;

	for (after = before; after < upper; after++)
	{
		/* check if array after is lesser than array pivot */
		if ((*array)[after] < (*array)[pivot])
		{
			swap_pos(array, before, after);
			before += 1;
		}
	}

	/* swap pivot to its original position */
	swap_pos(array, before, after);
	return (before);
}
/**
 * sorter - recursively sorts the array given
 *
 * @array: array to be sorted
 * @lb: lower bound
 * @ub: upper bound
 */
void sorter(int **array, size_t lb, size_t ub)
{
	size_t sorted_index;
	/* recursive breakpoint */
	if (lb < ub)
	{
		sorted_index = partition(array, lb, ub);

		/* perform recursive sort */
		if (sorted_index)
		{
			sorter(array, lb, sorted_index - 1);    /* sort lower boundary */
			print_array(*array, ub + 1);
		}
		if (sorted_index != ub)
		{
			sorter(array, sorted_index + 1, ub);    /* sort upper boundary */
			print_array(*array, ub + 1);
		}
	}
}

/**
 * quick_sort - applies the quick sort algorithm to sort
 * a given array
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	/* create the sorter function to recursively sort the array */
	sorter(&array, 0, size - 1);
}

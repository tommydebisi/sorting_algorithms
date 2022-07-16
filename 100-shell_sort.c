#include "sort.h"

/**
 * find_pow - find power of a number
 * @x: the number
 * @y: the value of power
 *
 * Return: the power of x
 */
int find_pow(int x, int y)
{
	if (y == 0)
		return (1);

	return (x * find_pow(x, y - 1));
}

/**
 * seq_generator - generate sequence
 * @size: size of sequence
 *
 * Return: pointer to the address of sequence
 */
int *seq_generator(size_t size)
{
	size_t n = 0;
	int i = 0, nth_term, *sequence;

	sequence = malloc(sizeof(int) * size);
	if (sequence == NULL)
		return (NULL);

	nth_term = 0;
	while (n < size)
	{
		nth_term = nth_term + find_pow(3, i);
		sequence[i] = nth_term;
		n++;
		i++;
	}

	return (sequence);
}

/**
 * find_seq_length - find length of sequence
 * @sequence: pointer to the address of sequence
 *
 * Return: length of sequence
 */
int find_seq_length(int *sequence)
{
	int count = 0, i = 0;

	while (sequence[i])
	{
		count++;
		i++;
	}
	return (count);
}
/**
 * shell_sort - sorts using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, seq_size, *sequence, seq_index = 0;

	if (size == 2)
		return;

	sequence = seq_generator(size);
	if (sequence == NULL)
		return;
	seq_size = find_seq_length(sequence);

	while (seq_index < seq_size)
	{
		for (i = sequence[seq_index]; i < size; i++)
		{
			temp = array[i];
			for (j = i; array[j - sequence[seq_index]] > temp; j -= sequence[seq_index])
			{
				array[j] = array[j - sequence[seq_index]];
			}
			array[j] = temp;
			print_array(array, size);
		}
		seq_index++;
	}
	free(sequence);
}

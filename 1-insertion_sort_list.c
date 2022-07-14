#include "sort.h"

/**
 * size_of_list - fid lenght of list
 * @list: pointer to head of list
 *
 * Return: size of list.
 */
size_t size_of_list(listint_t *list)
{
	size_t size;

	size = 0;

	if (list == NULL)
		return (size);	/*return 0*/
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to pointer to the head
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	size_t size, i = 0;	/*@n: size of list*/
	listint_t *end_of_list;
	int temp;

	size = size_of_list(*list);
	while (*list)
	{
		*list = (*list)->next;
		end_of_list = *list;
	}
	while (i < size)
	{
		temp = end_of_list->n;
		while (end_of_list->prev && temp < end_of_list->prev->n)
		{
			end_of_list->next->n = end_of_list->prev->n;
			end_of_list->prev;
		}
		end_of_list->prev->n = temp;
		i++;
	}
}

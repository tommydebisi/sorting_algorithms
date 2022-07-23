#include "deck.h"

/**
 * get_value_int - get numeric value for deck value
 * @value: deck value
 * Return: numeric value for deck value
 */
int get_value_int(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);
	else if (strcmp(value, "Jack") == 0)
		return (11);
	else if (strcmp(value, "Queen") == 0)
		return (12);
	else if (strcmp(value, "King") == 0)
		return (13);
	else
		return (atoi(value));
}

/**
 * compare - compare function for deck sort
 * @a: first deck_node
 * @b: second deck_node
 * Return: 1 if a > b, -1 if b > a, else 0
 */
int compare(const void *a, const void *b)
{
	deck_node_t *a_deck = *(deck_node_t **) a;
	deck_node_t *b_deck = *(deck_node_t **) b;

	int a_kind = a_deck->card->kind;
	int b_kind = b_deck->card->kind;

	int a_value, b_value;

	if (a_kind == b_kind)
	{
		a_value = get_value_int(a_deck->card->value);
		b_value = get_value_int(b_deck->card->value);
		return (a_value - b_value);
	}
	return (a_kind - b_kind);
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: list of deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *ptrs[52];
	deck_node_t *current = *deck;
	int i = 0;

	/* make the array of pointers */
	for (; current && i < 52; current = current->next, i++)
		ptrs[i] = current;

	/* sort the array with qsort */
	qsort(ptrs, 52, sizeof(deck_node_t *), compare);

	/* reconstruct the **deck */
	ptrs[0]->prev = NULL;
	ptrs[0]->next = ptrs[1];
	*deck = current = ptrs[0];
	for (i = 1; i < 52; i++)
	{
		current->next = ptrs[i];
		current = ptrs[i];
		current->prev = ptrs[i - 1];
	}
	current->next = NULL;
}

#include "sort.h"
/**
 * insertion_sort_list - function to implement insertion
 *  sort with doubly linked lists
 * @list: list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		listint_t *temp = current;

		while (temp->prev && temp->n < temp->prev->n)
		{
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (!temp->prev)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		current = current->next;
	}
}

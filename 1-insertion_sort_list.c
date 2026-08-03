#include "sort.h"

/**
 * insertion_sort_list - sorts list
 * @list: pointer to head pointer
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *prev, *next;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
curr = (*list)->next;
while (curr != NULL)
{
next = curr->next;
prev = curr->prev;
while (prev != NULL && prev->n > curr->n)
{
prev->next = curr->next;
if (curr->next != NULL)
curr->next->prev = prev;
curr->prev = prev->prev;
curr->next = prev;
if (prev->prev != NULL)
prev->prev->next = curr;
else
*list = curr;
prev->prev = curr;
print_list(*list);
prev = curr->prev;
}
curr = next;
}
}

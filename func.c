#include "monty.h"
extern stack_t *head;
void push(int n)
{
	stack_t *cur = head;
	stack_t *newnode = malloc(sizeof(stack_t));
	newnode->n = n;
	newnode->next = NULL;

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (cur != NULL)
	{
		if (cur->next == NULL)
		{
			cur->next = newnode;
			newnode->prev = cur;
			break;
		}
		cur = cur->next;
	}
}
void pall(void)
{
	stack_t *cur = head;
	/*loop to the last node*/
	while (cur != NULL)
	{
		cur = cur->next;
	}
	/*loop backwards*/
	while (cur->prev != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->prev;			
	}
}

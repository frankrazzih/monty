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
	if (cur == NULL)
	{
		head = newnode;
	}
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		newnode->prev = cur;
	}
}
void pall(void)
{
	stack_t *cur = head;
	if (cur == NULL)
	{
		return;
	}
	/*loop to the last node*/
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	/*loop backwards*/
	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->prev;			
	}
}
void pint(void)
{
	stack_t *cur = head;
	if (cur == NULL)
	{
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	printf("%d\n", cur->n);
}

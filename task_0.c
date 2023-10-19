#include "monty.h"
	stack_t *linked_l;
	linked_l = malloc(sizeof(*linked_l));
	linked_l->next = NULL;
	linked_l->prev = NULL;
	head = linked_l;
int main(int argc, char *argv[])
{
	int n;
	int line_count = 0;
	char *buff;
	char *opcode;
	FILE *file = fopen(argv[1], "r");

	if (argc < 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		perror("Error: Can't open file argv[1]");
		exit(EXIT_FAILURE);
	}
	while (fgets(buff, sizeof(buff), file) != NULL)
	{
		line_count++;
		/*search for push or pall*/
		opcode = strtok(buff, " ");
		if (opcode == NULL)
		{
			continue;
		}
		if (opcode != "push" || opcode != "pall")
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_count, opcode);
			exit(EXIT_FAILURE);
		}
		if (opcode == "pall")
		{
			/*call the printing function*/
			pall();
		}
		if (opcode == "push")
		{
			/*get 2nd token*/
			opcode = strtok(NULL, " ");
			/*look for an int*/
			while (opcode != NULL)
			{
				/*check for a valid int*/
				if (isdigit(opcode) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer", line_count);
					exit(EXIT_FAILURE);
				}
			}
			/*convert to int*/
			n = atoi(opcode);
			/*2nd token confirmed an int so call pushing function*/
			push(n);
		}
	}
}

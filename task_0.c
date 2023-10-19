#include "monty.h"
void pall(void);
void push(int n);
stack_t *head = NULL;
int main(int argc, char *argv[])
{
	stack_t *linked_l = malloc(sizeof(stack_t));
	int n;
	int line_count = 0;
	char *buff = malloc(sizeof(char *) * 1024);
	char *opcode;
	FILE *file = fopen(argv[1], "r");

	linked_l->next = NULL;
	linked_l->prev = NULL;
	head = linked_l;
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file argv[1]\n");
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
		if (strcmp(opcode, "pall") == 0)
		{
			/*call the printing function*/
			pall();
		}
		if (strcmp(opcode, "push") == 0)
		{
			/*get 2nd token*/
			opcode = strtok(NULL, " ");
			/*look for an int*/
			while (*opcode != '\0')
			{
				/*check for a valid int*/
				if (!isdigit(*opcode))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_count);
					exit(EXIT_FAILURE);
				}
				opcode++;
			}
			/*convert to int*/
			n = atoi(opcode);
			/*2nd token confirmed an int so call pushing function*/
			push(n);
		}
		else
			/*check if the first token is either push or pall*/
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	free(buff);
	free(linked_l);
	return (0);
}

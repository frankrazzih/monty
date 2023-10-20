#include "monty.h"
stack_t *head = NULL;
int main(int argc, char *argv[])
{
	stack_t *linked_l = malloc(sizeof(stack_t));
	int n;
	int line_count = 0;
	char *buff = malloc(sizeof(char *) * 1024);
	char *opcode, *temp;
	FILE *file = fopen(argv[1], "r");
	char *delim = " \n";
	char *pal = "pall";
	char *psh = "push";

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
	/*read line from file*/
	while (fgets(buff, sizeof(buff), file) != NULL)
	{
		line_count++;
		/*search for push or pall*/
		opcode = strtok(buff, delim);
		if (opcode == NULL)
		{
			continue;
		}
		if (strcmp(opcode, "pint") == 0)
		{
			pint();
			continue;
		}
		if (strcmp(opcode, pal) == 0)
		{
			/*call the printing function*/
			pall();
			continue;
		}
		if (strcmp(opcode, psh) == 0)
		{
			/*get 2nd token*/
			opcode = strtok(NULL, delim);
			temp = opcode;
			if (opcode != NULL)
			{
				/*look for an int*/
				while (*temp != '\0')
					{
					if (!isdigit(*opcode))
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_count);
						exit(EXIT_FAILURE);
					}
					temp++;
				}
				/*convert to int*/
				n = atoi(opcode);
				/*2nd token confirmed an int so call pushing function*/
				push(n);
				continue;
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_count);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, opcode);
			exit(EXIT_FAILURE);
		}
		free(buff);
	}
	fclose(file);
	free(linked_l);
	return (0);
}

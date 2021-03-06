#include "monty.h"

/**
* free_list - free linked list
*
*@head: linked list
*
*Return: void
**/
void free_list(stack_t *head)
{
	stack_t *aux;

	for (aux = head; head != NULL; aux = head)
	{
		head = head->next;
		free(aux);
	}
}

/**
* s_num - function that check if a string has integers with the global var.
*
*Return: void
**/
int s_num(void)
{
	int i, f = 1;

	if (number == NULL)
		return (0);
	if (number[0] == '-')
	{
		for (i = 1; f == 1 && number[i] != '\0'; i++)
		{
			if (number[i] < 48 || number[i] > 57)
			{
				number = NULL;
				f = 0;
			}
		}
	}
	else
	{
		for (i = 0; f == 1 && number[i] != '\0'; i++)
		{
			if (number[i] < 48 || number[i] > 57)
			{
				number = NULL;
				f = 0;
			}
		}
	}
	return (f);
}

/**
* line - function that tokenize every string in the line
* @head: pointer
* @buf: buffer
* @count: count lines
* Return: int
*/
int line(stack_t **head, char *buf, int count)
{
	char *delimiters = " \t\r\n\v\f", *toks = NULL;
	int i, n, f = 0;
	instruction_t func[] = {
	{"push", node_push}, {"pall", pall}, {"pop", node_pop},
	{"pint", node_pint}, {"swap", node_swap}, {"sub", node_sub},
	{"mul", node_mul}, {"nop", node_nop}, {"add", node_add},
	{NULL, NULL}
	};

	toks = strtok(buf, delimiters);
	number = strtok(NULL, delimiters);
	s_num();
	if (toks == NULL)
		return (1);
	for (i = 0; func[i].opcode != NULL && f == 0; i++)
	{
		n = strcmp(toks, func[i].opcode);
		if (n == 0)
		{
			func[i].f(head, count);
			f = 1;
		}
	}
	if (f == 0)
	{
		dprintf(STDERR_FILENO, "L%i: unknown instruction %s\n", count, toks);
		return (0);
	}
	return (1);
}

/**
 * main - this is the  main
 * @argc: argc
 * @argv: argv
 * Return: int
 */
int main(int argc, char *argv[])
{
	char *buf;
	long len;
	FILE *f;
	int num, count = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fseek(f, 0, SEEK_SET);
	buf = malloc(len);
	if (!buf)
	{	dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, len, f))
	{	num = line(&head, buf, count);
		if (num != 1)
		{
			free(buf);
			free_list(head);
			fclose(f);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	free_list(head);
	free(buf);
	fclose(f);
	exit(EXIT_SUCCESS);
}

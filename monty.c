#include "monty.h"

/**
* s_num - function that check if a string has integers with the global var.
*
*Return: void
**/
void s_num()
{
	int i;

	if (number == NULL)
		return;
	if (number[0] == '-')
	{
		for (i = 1; number[i] != '\0'; i++)
		{	
			if (number[i] <= 48 || number[i] >= 57)
				number = NULL;
		}
	}
	else
	{
		for (i = 1; number[i] != '\0'; i++)
		{	
			if (number[i] <= 48 || number[i] >= 57)
				number = NULL;
		}
	}
}

/**
* line: function that tokenize every string in the line
*
*
*
*/
int line (stack_t **head, char *buf, int count)
{
	char *delimiters = " \t\r\n\v\f", *toks = NULL;
	int i, n, f = 0;
	instruction_t func[] = {
	{"push", node_push}, {"pall", pall}, {"pop", node_pop},
	{"pint", node_pint}, {NULL, NULL}
	};

	toks = strtok(buf, delimiters);
	number = strtok(NULL, delimiters); 
	s_num();
	if (number == NULL && strcmp(toks, "pall") != 0)
		return (0);
	for (i = 0; func[i].opcode != NULL && f == 0; i++)
	{
		n = strcmp(toks, func[i].opcode);
		if (n == 0)
		{
			func[i].f(head, count);
			f = 1;
		}
	}
	return (1);

}

int main(int argc, char *argv[])
{
	char *buf;
	long len;
	FILE *f;
	int num, count = 1;
	stack_t *head = NULL;

	if (argc != 2)
		return(-1);
	
	f = fopen(argv[1], "r");
	if (!f)
		return (0);
	fseek (f, 0, SEEK_END);
	len = ftell (f);
	fseek (f, 0, SEEK_SET);
	buf = malloc (len);
	if (!buf)
		return (0);
	while (fgets(buf, len, f))
	{
		/*fgets(buf, len, f);*/
		num = line(&head, buf, count);
		if (num != 1)
			return (0);
		count++;
	}
	return (0);
	
}

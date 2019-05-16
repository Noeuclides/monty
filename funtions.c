#include "monty.h"
/**
 * s_num - function that look for a interger in a string
 *
 *@p: string to compare with integers
 *
 *Return: 0 if the string is not an integer, 1 otherwise
 **/
int s_num(char *p)
{
	int j = atoi(p);
	if (j >= 0 && j <= 9)
		return(1);
	return (0);
}

/**
 * s_push - function that look for a specific word in a string
 *
 *@p: string to compare with the specific word
 *
 *Return: 0 if the string is not the string looked, 1 otherwise
 **/
int s_push(char *p)
{
	char *push = "push";
	int i;

	if (strlen(p) != strlen(push))
		return (0);
	for (i = 0; p[i] != '\0'; i++)
	{
		if (p[i] != push[i])
			return (0);
	}
	return (1);
}


/**
 * line: function that tokenize every string in the line
 *
 *
 *
 */
char *line (char *buf)
{
	char **search; /*double pointer that store every string in the line*/
	char *delimiters = " \t\r\n\v\f", *toks;
	int id, i = 1, n;

	toks = strtok(buf, delimiters);
	search[0] = toks;
	id = s_push(search[0]);

	if (id == 1)/*means that the word is push, and the next string most be a number*/
	{
		toks = strtok(NULL, delimiters);
		search[0] = toks;
		n = s_num(search[0]);
			printf("earch es ...> %s", search[0]);
		if (n == 1)/*means that the string is an integer*/
			return (search[0]);
		return (NULL);
	}
	else
	{
		while (toks)
		{
			toks = strtok(NULL, delimiters);
			search[i] = toks;
				id = s_push(search[i]);
			if (id == 1)
			{
				toks = strtok(NULL, delimiters);
				search[0] = toks;
					n = s_num(search[0]);
				if (n == 1)/*means that the string is an integer*/
					return (search[0]);
				return (NULL);
			}
		}

	}
	return (NULL);

}

void (*find_op(char *code))(stack_t **stack, unsigned int line_number)
{
	int i, length;
	instruction_t inst[] = {
		{"push", _strncmp},
		{"pall", _strncmp},
		{NULL, NULL}
	};

	length = _length_word(code);
	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (strncmp(code, inst[i].opcode, length))
			return (inst[i].f);
	}
	return (inst[i].f);
}

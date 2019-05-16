#include "monty.h"

/**
* s_num - function that check if a string has integers
*
*@p: string to compare with integers 
*
*Return: 0 if the string is not an integer, 1 otherwise
**/
int s_num(char *p)
{
	int i, f = 1;
	
	
	if (p[0] == '-')
	{
		for (i = 1; p[i] != '\0'; i++)
		{	
			if (p[i] <= 48 || p[i] >= 57)
				return (0);
		}
	}
	else
	{
		for (i = 1; p[i] != '\0'; i++)
		{	
			if (p[i] <= 48 || p[i] >= 57)
				return (0);
		}
	}
	return (1);
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
	char *pall = "pall";
	int i, n = 1;

	if (strlen(p) != strlen(push))
		return (0);
	for (i = 0; p[i] != '\0'; i++)
	{
		if (p[i] != push[i] && p[i] != pall[i])
			printf("no es igual: %s\n", p);
		else if (p[i] == pall[i])
			n = 2;
		else
			n = 1;
	}
	printf("s_push function: %i\n", n); 
	if (n == 2)
		return (2);
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
	int num, id, i = 1, n;

	toks = strtok(buf, delimiters);
	search[0] = toks;
	id = s_push(search[0]);
	printf(" id en line: %i\n", id);
	if (id == 1)/*means that the word is push, and the next string most be a number*/
	{
		toks = strtok(NULL, delimiters);	
		search[0] = toks;
		n = s_num(search[0]);
		printf("toks en line: %s\n", toks);
		if (n == 1)/*means that the string is an integer*/
			return (search[0]);			
	}
	return (NULL);

}

int main(int argc, char *argv[])
{
	char *buf, *toks;
	long len;
	FILE *f;
	int i = 1, num;

	printf("%s", argv[1]);
	f = fopen(argv[1], "r");
	
	if (!f)
		return (0);
	fseek (f, 0, SEEK_END);
	len = ftell (f);
	fseek (f, 0, SEEK_SET);
	buf = malloc (len);
	if (!buf)
		return (0);
	while (!feof (f))
	{
		fgets(buf, len, f);
		printf("%s\n", buf);
		toks = line(buf);
	 	printf("toks main: %s", toks);	
		if (!toks)
			return (0);
		num = atoi(toks);
		printf("num main: %i", num);
		/*crear nodo y linked list*/
	}
	printf("%s", buf);
	
	return (0);
	
}

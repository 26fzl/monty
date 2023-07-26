#include "monty.h"
#include "lists.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, v, w;

	flag = 0;
	w = 0;

	for (v = 0; s[v] != '\0'; v++)
	{
		if (s[v] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int x, y = 0, len = 0, words, v = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (x = 0; x <= len; x++)
	{
		if (isspace(str[x]) || str[x] == '\0' || str[x] == '\n')
		{
			if (v)
			{
				end = x;
				tmp = (char *) malloc(sizeof(char) * (v + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[y] = tmp - v;
				y++;
				v = 0;
			}
		}
		else if (v++ == 0)
			start = x;
	}

	matrix[y] = NULL;

	return (matrix);
}

/**
 * free_everything - frees arrays of strings
 * @args: array of strings to free
 */
void free_everything(char **args)
{
	int x;

	if (!args)
		return;

	for (x = 0; args[x]; x++)
		free(args[x]);

	free(args);
}

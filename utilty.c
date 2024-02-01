#include "monty.h"
/**
 * strtok_line - handles and tokenizes the line read from file
 *
 * @line: the line to tokenize
 *
 * Return: tokens as an array of strings
 */


char **strtok_line(char *line)
{
	int i = 0, wcount = 0, in = 0;
	char **args = NULL;

	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
			in = 0;
		else if (in == 0)
		{
			in = 1;
			wcount++;
		}
		i++;
	}

/**	args = malloc(sizeof(char *) * (wcount + 1));
	if (!args)
		return (NULL);*/

	i = 0;
	while ((args[i] = strtok(i == 0 ? line : NULL, " \n\t")))
		i++;

	return (args);
}

/**
 * free_args - frees the argument tokens array
 *
 * @args: array of tokens
 */


void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		args[i] = NULL;
		i++;
	}
	args = NULL;
}
/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

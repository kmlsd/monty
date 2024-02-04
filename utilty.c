#include "monty.h"
/**
 * strtok_line - handles and tokenizes the line read from file
 *
 * @line: the line to tokenize
 *
 * Return: tokens as an array of strings
 */

char **strtok_line(char *line, unsigned int line_nb)
{
        int i = 0;
        char **args, *ars_token;
        char *d = "' '$\t\n";
	stack_t *stack = NULL;

        args = malloc(sizeof(char *)* sizeof(line));
        ars_token = strtok(line, d);

	while(ars_token)
        {
	args[i] = malloc(sizeof(ars_token));
	strcpy(args[i], ars_token);
	i++;
	ars_token = strtok(NULL, d);
	

        }
	if (args[0] && call_monty_func(args, &stack, line_nb) == 1)
	{
                free_args(args);
                free_stack(stack);
	}
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
		free(args[i]);
		i++;
	}
	free(args);
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

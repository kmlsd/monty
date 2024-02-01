#include "monty.h"
/**
 * main - entry point of our monty program
 * @argc: the amount of arguments given to the program
 * @argv: the array of arguments given to the program
 *
 * Return: EXIT_SUCCESS if no error has occures, otherwise EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	FILE *fp;

	META.error = 0;
	META.state = STACK;
	
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (-1);
		
	}

	fp = fopen(argv[1], O_RDONLY);
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (-1);
	}
	monty_ex(fp);
	fclose(fp);

	return (0);

}

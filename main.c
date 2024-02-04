#include "monty.h"
#define _GNU_SOURCE
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

        fp = fopen(argv[1], "r");
        if (argc < 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit (EXIT_FAILURE);
        }
	if (fp == NULL)
        { 
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit (EXIT_FAILURE);
        }
	if (fp != NULL)
	read_input(fp);
	else
	{
	fclose(fp);
	exit(EXIT_FAILURE);
	}
        fclose(fp);
        exit (EXIT_SUCCESS);

}

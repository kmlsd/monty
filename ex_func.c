#include "monty.h"

/**
 * free_stack - frees the stack after runtime
 *
 * @stack: the program stack
 */

void free_stack(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
	
}
/**
* read_input - read file input
* @fp: file pointer
* Return: void 
*/
void read_input(FILE *fp)
{
	unsigned int line_nb = 0;
        char *line = NULL;
        char **ar = NULL;
        ssize_t read_file;
        size_t len = 0;

	while ((read_file = getline(&line, &len, fp)) > -1)
	{
		fprintf(stderr, "USAGE: monty file kamal  \n");
                ar = strtok_line(line, line_nb);
                line_nb++;

        }
        free(ar);
	free_args(ar);
	free(line);
      
}


/**
 * call_monty_func - selects the correct function to call
 *
 * @args: the array of args
 * @stack: the program stack
 * @line_nb: the line number
 *
 * Return: EXIT_SUCCESS if success, EXIT_FAILURE if failure
 */

int call_monty_func(char **args, stack_t **stack, unsigned int line_nb)
{
	int i = 0;
	instruction_t instructions[] = {
		{"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add}, {"nop", _nop},
		{"sub", _sub}, {"div", _div}, {"mul", _mul}, {"mod", _mod},
		{"pchar", _pchar}, {"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{NULL, NULL}
	};

	if (strcmp(args[0], "push") == 0)
	{
		_push(stack, line_nb, args[1]);
		return (META.error);
	}

	if (strcmp(args[0], "stack") == 0)
	{
		META.state = STACK;
		return (META.error);
	}

	if (strcmp(args[0], "queue") == 0)
	{
		META.state = QUEUE;
		return (META.error);
	}

	while (instructions[i].opcode)
	{
		if (strcmp(args[0], instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_nb);
			return (META.error);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_nb, args[0]);
	META.error = 1;
	return (1);
}

#include "monty.h"

info_t infos = {NULL, NULL, 0, 0};

/**
 * trimLeadingSpaces - to remove all leading spaces from string
 * @str: it is string to trimmed
 */
void trimLeadingSpaces(char *str)
{
	int i, j;
	int leadingSpaces = 0;

	if (str == NULL)
	{
		printf("Input string is NULL.\n");
		return;
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		break;
		leadingSpaces++;
	}

	for (i = leadingSpaces, j = 0; str[i] != '\0'; i++, j++)
	{
		str[j] = str[i];
	}
	str[j] = '\0';
}

/**
 * condenseSpaces - it is condense consecutive spaces in string
 * @str: it is string to condensed
 */
void condenseSpaces(char *str)
{
	int i, j;
	int spaceFound = 0;
	char *newStr;

	if (str == NULL)
	{
		printf("Input string is NULL.\n");
		return;
	}

	newStr = (char *)malloc(strlen(str) + 1);
	if (newStr == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (!spaceFound)
			{
				newStr[j++] = ' ';
				spaceFound = 1;
			}
		}
		else
		{
			newStr[j++] = str[i];
			spaceFound = 0;
		}
	}

	newStr[j] = '\0';
	strcpy(str, newStr);
	free(newStr);
}

/**
 *instruction - it should call right function
 *@opcode: command
 *@stack: it is the head of list
 *@lNum: it is line number
 *Return: it must returns 0 for success
 */

int instruction(char *opcode, stack_t **stack, unsigned int lNum)
{
	unsigned int i = 0;
	instruction_t opstruct[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"mul", mul}, {"div", divi},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {"queue", queue},
		{"stack", fstack}, {NULL, NULL}
	};

	while (opstruct[i].opcode)
	{
		if (strcmp(opcode, opstruct[i].opcode) == 0)
		{
			opstruct[i].f(stack, lNum);
		return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lNum, opcode);
	return (1);
}

/**
 *main - it is main entry
 *@ac: argument count
 *@av: it is argument vector
 *Return: it must reurn EXIT_SUCCESS
 */

int main(int ac, char *av[])
{
	FILE *file;
	char line[MONTY_LEN], *opcode;
	stack_t *stack = NULL;
	int n;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	infos.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		infos.lNum++;
		trimLeadingSpaces(line);
		if (line[0] == '#' || line[0] == '\n')
			continue;
		condenseSpaces(line);
		opcode = strtok(line, " \n");
		infos.arg = strtok(NULL, " \n");
		n = instruction(opcode, &stack, infos.lNum);
		if (n == 1)
		{
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

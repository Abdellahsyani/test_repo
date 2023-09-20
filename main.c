#include "main.h"

int main(int ac, char **av);

/**
 * main - Entry point
 * @argc: argument to count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int ac, char **av)
{
	char *stradd = NULL, *stradd_cpy = NULL;
	size_t n = 0;
	ssize_t retval;
	const char *del = " \n";
	int cntok = 0;
	char *tok;
	int x;

	(void)ac;
	myenv();

	while (1)
	{
		if (isatty(0))
			write(STDOUT_FILENO, "(darkshell)$ ", 13);
		retval = getline(&stradd, &n, stdin);

		if (retval == -1)
		{
			if (isatty(0))
				_puts("\n");
			free(stradd), stradd = NULL;
			return (-1);
		}
		stradd_cpy = malloc(sizeof(char) * (retval + 2));

		if (stradd_cpy == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}

		_strcpy(stradd_cpy, stradd);

		tok = strtok(stradd, del);
		while (tok != NULL)
		{
			cntok++;
			tok = strtok(NULL, del);
		}
		cntok++;

		av = malloc(sizeof(char *) * cntok);

		tok = strtok(stradd_cpy, del);

		for (x = 0; tok != NULL; x++)
		{
			av[x] = malloc(sizeof(char) * (_strlen(tok) + 1));
			_strcpy(av[x], tok);

			tok = strtok(NULL, del);
		}
		av[x] = NULL;

		excom(av);
		free(av);
	}
	free(stradd);
	free(stradd_cpy);
	return (0);
}

#include "shell.h"
char *read_line()
{
	char *read = NULL;
	size_t count = 0;
	ssize_t n_char;

	if (isatty(0))
		write(1, "$ ", 3);
	n_char = getline(&read, &count, stdin);
	if (n_char == -1)
	{
		free(read), read = NULL;
		return (NULL);
	}
	return (read);
}


int main(int ac, char **argv)
{
	char *read = NULL;
	char **cmd = NULL;
	int stat = 0, num = 0;
	(void)ac;

	while (1)
	{
		read = read_line();
		if (read == NULL)
		{
			if (isatty(0))
				write(1, "\n", 2);
			return (stat);
		}
		num++;

		cmd = splitazer(read);
		if (!cmd)
			continue;
		if (_binaya_ton(cmd[0]))
			_bin_handlon(cmd, argv, &stat, num);
		else
			stat = execute(cmd, argv, num);
	}
}

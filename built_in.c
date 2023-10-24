#include "shell.h"

int _binaya_ton(char *cmd)
{
	char *bin[] = {
		"exit",
		"env",
		NULL
	};
	int i = 0;
	while (bin[i])
	{
		if (_strcmp(cmd, bin[i]) == 0) 
			return (1);
		i++;
	}
	return (0);
}

void _bin_handlon(char **cmd, char **argv, int *stat, int num)
{
	(void)argv;
	(void)num;

	if (_strcmp(cmd[0], "exit") == 0)
		_quit_pro(cmd, stat);
	else if (_strcmp(cmd[0], "env") == 0)
		_environ_write(cmd, stat);
}

void _quit_pro(char **cmd, int *stat)
{
	free2D(cmd);
	exit(*stat);
}

void _environ_write(char **cmd, int *stat)
{
	int i = 0;
	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 2);
		i++;
	}
	free2D(cmd);
	(*stat) = 0;
}

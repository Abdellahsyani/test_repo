#include "shell.h"
void error_one(char *ism, char *cmd, int num)
{
	char *ofdix;
	ofdix = _itoa(num);

	write(1, ism, _strlen(ism));
	write(1, ": ", 3);
	write(1, ofdix, _strlen(ofdix));
	write(1, ": ", 3);
	write(1, cmd, _strlen(cmd));
	write(1, ": not found\n", 13);
	free(ofdix);
}

int execute(char **cmd, char **argv, int num)
{
	char *allcmd;
	pid_t child;
	int status;

	allcmd = handle_path(cmd[0]);
	if (!allcmd)
	{
		/*char *res = argv[0];
		char *res1 = cmd[0];
		char *ofdix;
		ofdix = _itoa(num);
		write(1, res, _strlen(res));
		write(1, ": ", 3);
		write(1, res1, _strlen(res1));
		write(1, ": ", 3);
		write(1, ofdix, _strlen(ofdix));
		write(1, ": not found\n", 13);*/
		error_one(argv[0], cmd[0], num);
		free2D(cmd);
		return (127);
	 }
	child = fork();
	if (child == 0)
	{
		if (execve(allcmd, cmd, environ) == -1)
		{
			free(allcmd), allcmd = NULL;
			free2D(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free2D(cmd);
		free(allcmd), allcmd = NULL;
	}
	return (WEXITSTATUS(status));
}

#include "main.h"

/**
 * excom - function for command execution
 * @argv: argument vector
 *
 */
int get_excom(char **mycomm, char **argv)
{
	pid_t pid;
	int stat, i;

	pid = fork();
	if (pid == 0)
	{
		if (execve(mycomm[0], mycomm, environ) == -1)
		{
			perror(argv[0]);
			free(mycomm);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
		free(mycomm);
	}
	return (WEXITSTATUS(stat));
}

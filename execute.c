#include "shell.h"

/**
 * excom - function for command execution
 * @argv: argument vector
 *
 */
<<<<<<< HEAD
int excom(char **argv, char **mycomm)
{

=======
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
>>>>>>> 0daf757094a348eca7fe8ce7cad7723a6b18b698

#include "main.h"

/**
 * excom - function for command execution
 * @argv: argument vector
 *
 */
void excom(char **argv)
{
	char *mycomm = NULL, *lastcom = NULL;
	pid_t mypid = fork();

	if (argv)
	{
		mycomm = argv[0];
		if (_strcmp(mycomm, "exit") == 0)
		{
			exit(127);
		}

		if (mypid < 0)
		{
			perror("Fork failed:");
			exit(127);
		}
		else if (mypid == 0)
		{
			lastcom = getmy_loc(mycomm);

			if (lastcom == NULL)
			{
				exit(1);
			}
			if (execve(lastcom, argv, NULL) == -1)
			{
				perror("There is an Error:");
				free(lastcom);
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(lastcom);
}

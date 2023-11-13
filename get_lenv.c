#include "shell.h"

char *shows_path(char *path)
{
	char *pam, *sort, *val, *nov;
	int i = 0;

	while (environ[i])
	{
		pam = _strdup(environ[i]);
		sort = strtok(pam, "=");
		if (_strcmp(sort, path) == 0)
		{
			val = strtok(NULL, "\n");
			nov = _strdup(val);
			free(pam);
			return (nov);
		}
		free(pam), pam = NULL;
		i++;
	}
	return (NULL);
}

char *handle_path(char *mycom)
{
	char *path, *fullpath, *pathdir;
	int i = 0;
	struct stat buff;

	while (mycom[i])
	{
		if (mycom[i] == '/')
		{
			if (stat(mycom, &buff) == 0) return (_strdup(mycom));
			else
				return (NULL);
		}
		i++;
	}
	path = shows_path("PATH");
	if (!path)
		return (NULL);

	pathdir = strtok(path, ":");
	for (; pathdir != NULL; pathdir = strtok(NULL, ":"))
	{
		fullpath = malloc(_strlen(pathdir) + _strlen(mycom) + 2);
		if (fullpath)
		{
			_strcpy(fullpath, pathdir);
			_strcat(fullpath, "/");
			_strcat(fullpath, mycom);

			if (stat(fullpath, &buff) == 0)
			{
				free(path);
				return (fullpath);
			}
			free(fullpath), fullpath = NULL;
		}
	}
	free(path);
	return (NULL);
}

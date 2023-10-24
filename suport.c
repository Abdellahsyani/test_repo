#include "shell.h"

void free2D(char **arr)
{
	int i;
	if (arr == NULL)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]), arr[i] = NULL;
	free(arr), arr = NULL;
}

int _strncmp(const char *S1, const char *S2, size_t num)
{
	size_t i;
	for (i = 0; i < num; i++)
	{
		if (S1[i] != S2[i])
			return (S1[i] - S2[i]);
		if (S1[i] == '\0')
			return (0);
	}
	return (0);
}
char *_itoa(int n)
{
	char buff[10];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	return (_strdup(buff));
}

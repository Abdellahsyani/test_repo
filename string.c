#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return:int
 */
int _strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
	{
		return (0);
	}
	else if (!s1)
	{
		return (-1);
	}
	else if (!s2)
	{
		return (1);
	}
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strdup - dulicates a string and return pointer to new string
 * @str: original string
 *
 * Return: NULL if str is null or no memory
 */
char *_strdup(char *str)
{
	char *dstr;
	int i = 0, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
		len++;

	dstr = (char *)malloc((sizeof(char) * len) + 1);
	if (dstr == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		dstr[i] = str[i];
		i++;
	}
	dstr[len] = '\0';

	return (dstr);
}

/**
 * _strcpy - copy the string pointed to by src to dest
 * @dest: char to check
 * @src: char to check
 *
 * Return: 0 (success);
 */
char *_strcpy(char *dest, char *src)
{
	int a;


	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcat - concatinates two strings
 * @dest: first character
 * @src: second character
 *
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strlen - returns the length of a string
 * @s: char to check
 * Return: 0 (success)
 */
int _strlen(char *s)
{
	size_t a = 0;

	for (; *s++ != '\0';)
		a++;
	return (a);
}
/**
 * _puts - prints out character to the standard output
 * @str: string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

#include "cypee.h"

/**
 * _strcmp - compares one string to another.
 * @s1: the first command string.
 * @s2: the second command string.
 * Return: the compared string (cmp).
 */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}

/**
 * _strlen - calculates the length of a string.
 * @s: command string.
 * Return: length of the command string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strdup - allocates size to a string.
 * @str: string.
 * Return: pointer (ptr).
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
 * _strchr - function that searches for a character in a string.
 * @str: the inputted command string.
 * @c: character to be searched for,
 * Return: NULL if character is not found.
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

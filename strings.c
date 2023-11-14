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

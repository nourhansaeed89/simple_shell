#include "myshell.h"
/**
 *_strcat - copy str to str
 *@dest: dest char
 *@src: source char
 *Return: dest
 *
 */

char *_strcat(char *dest, char *src)
{
	int ds = 0;
	int st = 0;

	while (dest[ds] != '\0')
	{
		ds++;
	}
	while (src[st] != '\0')
	{
		dest[ds] = src[st];
		ds++;
		st++;
	}
	dest[ds] = '\0';
	return (dest);
}

/**
 * _strcmp - compare string  values
 * @s1: input1
 * @s2: input2
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int c;

	for (c = 0; s1[c] != '\0' && s2[c] != '\0'; c++)
	{
		if (s1[c] != s2[c])
			return ((int)s1[c] - s2[c]);
	}
	return (0);
}

/**
 * _strlen - copy  function
 * @s: pointer
 * Return: char
 */

int _strlen(char *s)
{
	int ch = 0;

	while (*(s + ch) != '\0')
	{
		ch++;
	}

	return (ch);
}

/**
 *_strncmp -  function compares two strings.
 *@s1: input one
 *@s2: input two
 *@n: num of char
 * Return: num
 */

size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * _strcpy - func that copies the string
 * @dest: dest of  input
 * @src: source of input
 *
 * Return: char pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);

	return (dest);
}

#include "myshell.h"

char *_strchr(const char *s, int c);
size_t _strspn(const char *s1, const char *s2);
size_t _strcspn(const char *s1, const char *s2);

/**
 * _strtok -function that return the token of 1st and next str
 * @str: string to tokenize
 * @delim: delimit srt.
 * Return: str
 **/
char *_strtok(char *str, const char *delim)
{
	static char *x;

	if (str)
		x = str;
	else if (!x)
		return (0);
	str = x + _strspn(x, delim);
	x = str + _strcspn(str, delim);
	if (x == str)
		return (x = 0);
	x = *x ? *x = 0, x + 1 : 0;
	return (str);
}
/**
 * _strcspn - func that computes the length of string
 * @s1: input string
 * @s2: 2nd input
 * Return: the length of strg
 **/
size_t _strcspn(const char *s1, const char *s2)
{
	size_t l = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
			return (l);
		s1++, l++;
	}
	return (l);
}
/**
 * _strspn - function that return max
 * @s1: in1
 * @s2: in2
 * Return: length
 **/
size_t _strspn(const char *s1, const char *s2)
{
	size_t l = 0;

	while (*s1 && _strchr(s2, *s1++))
		l++;
	return (l);
}
/**
 * _strchr - function that return a pointer of located char
 * @s: string
 * @c: character
 * Return: char
 **/
char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

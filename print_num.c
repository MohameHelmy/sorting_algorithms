#include "sort.h"

/**
 * getMagnitude - gets mag
 * @n: arg
 * Return: the mag
*/
int getMagnitude(int n)
{
	int magnitude = 0;

	if (n == 0)
		return (1);

	if (n < 0)
	{
		magnitude++;
		n = -n;
	}

	while (n != 0)
	{
		magnitude++;
		n /= 10;
	}
	return (magnitude);
}

/**
 * convertToStr - converts int to str
 * @n: int to convert
 * Return: str
*/
char *convertToStr(int n)
{
	char *str;
	int i, isNegative = 0;
	int mag = getMagnitude(n);

	str = malloc(sizeof(char) * mag + 1);
	if (!str)
	{
		return (NULL);
	}
	if (n < 0)
	{
		str[0] = '-';
		isNegative = 1;
		n = -n;
	}

	for (i = mag - 1; i >= 0; i--)
	{
		if (i == 0 && isNegative)
		{
			continue;
		}

		str[i] = '0' + n % 10;
		n /= 10;
	}
	str[mag] = '\0';
	return (str);

}
/**
 * _putNum - function to print number
 * @n: number
*/
void _putNum(int n)
{
	char *str;

	str = convertToStr(n);
	if (!str)
	{
		return;
	}
	write(STDOUT_FILENO, str, getMagnitude(n));
	free(str);
}

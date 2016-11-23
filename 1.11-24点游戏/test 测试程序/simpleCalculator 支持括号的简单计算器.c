#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char op[4] = {'+', '-', '*', '/'};

float calc(float n1, float n2, char o)
{

    switch (o)
    {
    case '+':
	return (n1 + n2);
    case '-':
	return (n1 - n2);
    case '*':
	return (n1 * n2);
    case '/':
	if (n2 == 0)
	    return -30000;
	else
	    return (n1 / n2);
    default:
	exit(-1);
    }
}

int find(char *p)
{

    int i = 0;
    while (*p != '\0' && *p != '=' && i < 2)
	if (*p == '(')
	    return 1;
	else if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == ')')
	    i++, p++;
	else
	    p++;
    return 0;
}

float sum(char *p, float result)
{

    //9*(3+6*(7+8))=
    float a, b;
    do
    {
	if (*p == '(')
	{
	    if (*(++p) == '(')
	    {
		result = sum(p + 1, result);
		while (*p != ')')
		    p++;
		p++;
	    }
	    else
	    {
		result = sum(p, result);
		while (*p != ')')
		    p++;
		p++;
	    }
	}
	else if (*p >= '0' && *p <= '9')
	{

	    a = (float)atof(p);
	    while ((*p >= '0' && *p <= '9') || *p == '.')
		p++;
	    if (*(p + 1) == '(')
	    {
		result = calc(a, sum(p + 2, result), *p);
		return result;
	    }
	    else
	    {
		b = (float)atof(p);
		result = calc(a, b, *p);
		return result;
	    }
	}
	else if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == ')')
	{

	    if (*p == ')')
		p++;

	    if (find(p))
	    { //后面有'('
		char ch = *p;
		while (*p != '(')
		    p++; //p指向下一个'('
		result = calc(result, sum(p, 0), ch);
		while (*p != ')')
		    p++;
		p++; //p跳到下一个')'
	    }
	    else
	    {
		b = (float)atof(p + 1);
		result = calc(result, b, *p);
		p++;
		while ((*p >= '0' && *p <= '9') || *p == '.')
		    p++;
	    }
	}
	else
	    return result;
    } while (*p != '=');

    return result;
}

int main(void)
{

    char arr[30];
    memset(arr, 0, sizeof(char) * 30);
    scanf("%s", arr);

    float b;
    b = sum(arr, 0);
    printf("%g\n", b);

    return 0;
}

#include <string.h>
#include <stdlib.h>

int strEquals(char* a, char* b)
{
	if (strlen(a) != strlen(b))
		return 0;
	int i;
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

char* substr(char* s, int start, int length)
{
	char* ret = malloc(length+1);
	memcpy(ret, s+start, length);
	ret[length] = 0;
	return ret;
}

int find(char* s, char* sub, int start)
{
	int i;
	for (i = start; i < strlen(s); i++)
	{
		if (strEquals(substr(s, i, strlen(sub)), sub))
			return i;	
	}
	return -1;
}

void replaceChar(char* s, char x, char replaceWith, int start)
{
	int i;
	for (i = start; i < strlen(s); i++)
	{
		if (s[i] == x)
			s[i] = replaceWith;
	}
	
}
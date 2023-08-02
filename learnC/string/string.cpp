#include<stdio.h>
size_t mstrlen(const char* str)
{
	if (str == NULL)
		return 0;
	size_t len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}
char* mstrcat(char* destination, const char* source)
{
	if (destination == NULL)
		return NULL;
	if (source == NULL)
		return destination;
	char* ret = destination;
	while (*destination != '\0')
		destination++;
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	destination = '\0';
	return ret;
}
char* mstrcpy(char* destination, const char* source)
{
	if (destination == NULL)
		return NULL;
	if (source == NULL)
		return destination;
	char* ret = destination;
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	destination = '\0';
	return ret;
}
int mstrcmp(const char* str1, const char* str2)
{
	if (str1 == NULL && str2 == NULL)
		return 0;
	if (str1 != NULL && str2 == NULL)
		return 1;
	if (str1 == NULL && str2 != NULL)
		return -1;
	int ret = 0;
	while (1) {
		if (*str1 != *str2) {
			if (*str1 > *str2)
				ret = 1;
			else ret = -1;
			break;
		}
		else {
			if (*str1 == '\0' && *str2 == '\0')
				break;
			str1++;
			str2++;
		}
	}
	return ret;
}
int main()
{
	size_t len;
	len = mstrlen(NULL);
	printf("%d\n", len);
	len = mstrlen("");
	printf("%d\n", len);
	len = mstrlen("Hello");
	printf("%d\n", len);
	return 0;
}
/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<stdlib.h>
char removeSpaces(char *str) {
	if (str == NULL)
		return NULL;
	
	int i=0 , j=0;
	while (str[j]!='\0')
	{
		if (str[j] == ' ')
			j++;
		else
			str[i++] = str[j++];
	}
	str[i] = '\0';
}
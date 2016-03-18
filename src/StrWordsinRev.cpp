/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void stringrev(char str[],int i,int j)
{
	char temp;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

void str_words_in_rev(char *input, int len){
	int i = 0,k=0;
	stringrev(input, 0, len-1);
	while (k < len)
	{
		if (input[k] == ' ')
		{
			stringrev(input, i, k - 1);
			while (input[k] == ' ')
				k++;
			i = k;
		}
		else
			k++;
	}
	stringrev(input, i, k - 1);
}

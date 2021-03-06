/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

void stringcopy(char *d, char *s, int f, int l){
	int i = 0;
	if (f == -1 && l == -1)
	while (s[i] != '\0')
		d[i++] = s[i];
	else
	for (f = f; f <= l; f++)
		d[i++] = s[f];

	d[i] = '\0';
}

int compare(char **words, int count, char *s, int f, int l){
	int i, j = 0;
	for (i = 0; i < count; i++){
		while (words[i][j] != '\0'&&f <= l){
			if (words[i][j] != s[f])
				break;
			j++;
			f++;
		}
		if (words[i][j] == '\0'&&f>l)
			return i;
	}
	return -1;
}

char ** commonWords(char *str1, char *str2) {
	if (str1 == '\0' || str2 == '\0')
		return NULL;
	int s = 0, e = 0, i = 1, count = 0;

	char **common_words = (char**)malloc(SIZE*sizeof(char*));
	for (i = 0; i < SIZE; i++)
		common_words[i] = (char *)malloc(sizeof(char));
	i = 1;

	while (str1[i] != '\0'){
		if (str1[i] == ' '&&s != -1){
			e = i - 1;
			stringcopy(common_words[count++], str1, s, e);
			s = -1;
		}
		else if (str1[i - 1] == ' ')
			s = i;
		i++;
	}
	if (s != -1)
		stringcopy(common_words[count++], str1, s, i - 1);

	s = 0;
	int rc = 0, ind;
	char **res = (char **)malloc(SIZE*sizeof(char *));
	for (i = 0; i < SIZE; i++)
		res[i] = (char *)malloc(sizeof(char));
	i = 1;

	while (str2[i] != '\0'){
		if (str2[i] == ' '&&s != -1){
			e = i - 1;
			ind = compare(common_words, count, str2, s, e);
			if (ind != -1)
				stringcopy(res[rc++], common_words[ind], -1, -1);
			s = -1;
		}
		else if (str2[i - 1] == ' ')
			s = i;
		i++;
	}
	ind = compare(common_words, count, str2, s, i - 1);
	if (s != -1 && ind != -1)
		stringcopy(res[rc++], common_words[ind], -1, -1);
	free(common_words);
	if (rc == 0)
		return NULL;
	return res;
}

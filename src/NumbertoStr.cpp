/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<math.h>

int reverse(int num)
{
	int rem, sum = 0;
	while (num > 0)
	{
		rem = num % 10;
		sum = (sum * 10) + rem;
		num /= 10;
	}
	return sum;
}

void number_to_str(float number, char *str,int afterdecimal){
	int av, d,r,i=0;
	if (number < 0)
	{
		str[i++] = '-';
		number *= -1;
	}
	av = number;
	number -= av;
	d = number*pow(10.0, afterdecimal);
	av = reverse(av);
	d = reverse(d);
	while (av > 0)
	{
		r = av % 10;
		str[i++] = (char)(r + 48);
		av = av / 10;
	}
	if (d != 0)
		str[i++] = '.';
	while (d>0)
	{
		r = d % 10;
		str[i++] = (char)(r + 48);
		d = d / 10;
	}
	str[i] = '\0';
}

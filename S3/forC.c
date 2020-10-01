/*  Char counter 
	Steven Rubio
	29/09/2020
*/

#include<stdio.h>


int main(void)
{ 
	int blanks = 0, digits = 0, total_chars = 0;
	int c; //use for int value character
	for(; (c=getchar())!= EOF; total_chars++)
	{
		if (c == ' ')
			++blanks;
		else if (c >= '0' && c <= '9')
			++digits;
	};
	printf("Espacios en blanco = %d, digitos = %d, chars = %d\n",blanks,digits, total_chars);
		
	return 0;
}
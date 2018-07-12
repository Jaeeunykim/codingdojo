#include <stdio.h>


int getDigits(int i)
{
	while(i !=0)
	{
		printf("%d", GetLastDigit(i));
		i = RemoveLastDigit(i);
	}
	printf("\n");
}

int GetLastDigit(int i)
{
	return i%10;
}

int RemoveLastDigit(int i)
{
	return i/10;
}


void main()
{
	getDigits(12314);
	getDigits(678);
	return;
}

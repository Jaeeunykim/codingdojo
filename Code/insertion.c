#include <stdio.h>

char charlist[10]= "ABCEF";

int insert(char alph, int loc)
{
	int back, N, M;
	N = sizeof(charlist);
	M = 5;


//charlist크기와 charlist 배열요소의 크기 비교

	if(M < N)
	{
//back 위치 지정
		back = M+1;
	}
	else
		return 0;

	while(back >loc)
	{
//배열의 요소들 옮기기
	charlist[back] = charlist[back-1];
//배열 요소감소 back--;
	back = back -1;
	}

	charlist[back] = alph;
	M = M+1;
	return M;		

}

void print_arr()
{
	for(int i= 0; i<10; i++)
	{
		printf("%c", charlist[i]);
	}
	printf("\n");
}

int main()
{

	print_arr();

	char key[2] = "D";
	insert(key[0], 3);
	print_arr();
}

			

#include <stdio.h>

int search2 (int value, int* list, int count)
{
	int i,pos;
	pos = -1;

	for(i=0; i<count; i++)
	{
		if(value == *(list+i))
		{
			pos = i;
		}
	}
	return pos;
}




int search(int val)
{
	int pos;
	int i;
	pos = -1;

	for(i=0; i<10; i++)
	{
		if(val == num_List[i])
		{
			pos = i;
		}	
	}
	return pos;
}

//search 함수 :
//parameters : 찾는 값, 찾을 array, array의 크기
//return : 찾는 값이 있는 경우 해당 index. 없는 경우 -1

int search3(int v, int* array, int size)
{
	int index = -1;

	for(int i=0; i<size; i++)
	{
		if (v == array[i])
		{
			index = i;
			break;
		}
	}
	return index;
}

bool isContained(int v, int* array, int size)
{
	://v와 array각 값을 비교해서 구현
	bool founded= false;

	for(int i=0; i<size; i++)
	{
		if (v == array[i])
		{
			founded = true;
			break;
		}
	}
	return founded;
}

int main()
{

	int num_List[] = {0,1,2,3,4,5,6,7,8,9};
	
	printf("Hear is the list for search : ");

	for(int i=0; i<10; i++)
	{
		printf("%d ", num_List[i]);
	}
	printf("\n found the number  : %d\n", search(7));
 
	printf("\n found the number  : %d\n", search(20));
	printf("\n search2:%d\n", search2(7, num_List, 10)); 
	
}

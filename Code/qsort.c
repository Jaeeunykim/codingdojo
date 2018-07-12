#include <stdio.h>
#include <stdlib.h>

/*퀵소트!
1. 예외처리 (배열의 크기가 1개이하면 return)
2. 피벗을 배열의 중간위치에 있는 값으로 한다
3. 피벗을 맨앞자리로 스왑한다
4. 배열의 맨 앞(피벗)기준으로 1증가된 자리번째 수부터비교 작은값에 대한 범위를 만든다
5. 피벗을 작은값범위의 자리로 스왑시킨다
6. 피벗기준으로 작은범위와 큰범위 각각 재귀함수로 정렬한다
*/
void swap(int* v, int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qSort(int* v, int left, int right)
{
	int i, last, pivot;

	if(left>=right)
	{
		return;
	}

	last = left;
	pivot = (left+right)/2;

	swap(v, left, pivot);

	for(i=last+1; i <=right; i++)
	{
		if(v[i] < v[left])
		{
			++last;
			swap(v, last, i);
		}
	}

	swap(v, last, left);

	qSort(v, left, last-1);
	qSort(v, last+1, right);
}


int main()
{
	int arr[] = {3,57,11,7,20};
	int first = 0;
	int size = 5;

	qSort(arr, first, 4);

	for(int i=0; i<5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



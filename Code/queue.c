#include <stdio.h>
#define UNINIT -100

int rear, front;

int queue[5];

void init_queue();

void print_queue()
{
	for(int i=0; i<5; i++)
	{
		printf("%d  ", queue[i]);
	}
	printf("front : %d  rear : %d \n", front, rear);
}

void fake_changequeue();

int put();

int get();

int main()
{
	fake_changequeue();
	print_queue();

	init_queue();

	print_queue();
	//init 호출

	//queue에 2넣기 
	put(2);
	print_queue();

	put(3);
	print_queue();
	
	//queue배열의 맨앞에 있는 값빼기
	printf("call get : %d  front : %d  rear : %d \n",get(), front, rear);
	
	put(7);
	print_queue();

	put(9);
	print_queue();

	printf("call get : %d  front : %d  rear : %d \n",get(), front, rear);
}

void init_queue()
{
	//queue에 0 넣기 
	//rear, front -1값주기

	for(int i=0; i<5; i++)
	{
		queue[i] =0;
	}

	rear = front = UNINIT;
}

void fake_changequeue()
{
	queue[2] = 3;
	queue[4] = 6;
	rear = 3;
	front = 2;
}

int put(int item)
{
	if(rear == UNINIT)
	{
		rear=0;
	}
	else
	{
		rear = rear +1;
	}
	queue[rear] = item;
	
	if(front == UNINIT)
	{
		front = 0;
	}

}

//queue 배열에 front번째의 값을 빼낸다
//get을 부르면 front가 1증가 한다 

int get()
{
	int val;

	val = queue[front];
	front = front +1;
	return val;
}


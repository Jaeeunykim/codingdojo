#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
	int value;
	struct node* next;
}Node;

Node* top;

void initStack()
{
	top = NULL;
}

Node* createNode(int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->value = value;
	return node;
}

void push(int value)
{
	Node* temp = createNode(value);
	if(top == NULL)
	{
		top = temp;
	}
	else
	{
		temp->next = top;
		top = temp;
	}
} 

void pop()
{
	if(top == NULL)
	{
		printf("Stack is empty!\n");
	}
	else
	{
		printf("popped value : %d\n", top->value);
		Node* temp = top;
		top = temp->next;
		free(temp);
	}
}

void print_Stack()
{
	Node* temp;
	for(temp = top; temp != NULL; temp= temp->next)
	{
		printf("%d\n", temp->value);
	}
}

int main()
{
	initStack();
	push(5);
	push(19);
	push(11);
	push(20);

	print_Stack();
	pop();
	print_Stack();

	return 0;
}

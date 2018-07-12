#include <stdio.h>
#include <stdlib.h>
#define NUM_VERTEX 5

typedef struct vertex
{
	int value;
	struct vertex* neighbor;
}Vertex;

Vertex Graph[NUM_VERTEX];
int visited[NUM_VERTEX];

void initGraph()
{
	for(int i =0; i<NUM_VERTEX; i++)
	{
		Graph[i].value = 0;
		Graph[i].neighbor = NULL;
	}
}

void addGraph(int v, int w)
{
	Vertex* findLast;
	for(findLast = &Graph[v]; findLast->neighbor != NULL; findLast = findLast->neighbor)
	{
	}

	Vertex* temp = (Vertex*)malloc(sizeof(Vertex));
	temp->value = w;
	temp->neighbor = NULL;
	findLast->neighbor = temp;
}

void printGraph()
{
	Vertex* temp;
	for(int i = 0; i< NUM_VERTEX; i++)
	{
		printf("%d |", i);

		for(temp = Graph[i].neighbor; temp != NULL; temp = temp->neighbor)
		{
			printf(" %d ",temp->value);
		}
		//printf("\n");
	}
}

void DFS(int i)
{
	Vertex* temp;
	
	printf("%d ", i);
	temp = &Graph[i];
	visited[i] = 1;

	while(temp != NULL)
	{
		i = temp->value;
		if(!visited[i])
		{
			DFS(i);
		}
		temp = temp->neighbor;
	}
}


int main()
{
	initGraph();

	addGraph(0,1);
	addGraph(0,2);
	addGraph(1,2);
	addGraph(1,3);
	addGraph(2,3);
	addGraph(2,4);
	addGraph(3,4);

	printGraph();
	DFS(0);
}

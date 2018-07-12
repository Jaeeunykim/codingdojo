#include <stdio.h>
#include <stdlib.h>
#define NUM_VERTEX 5

int Graph[NUM_VERTEX][NUM_VERTEX];
int visited[NUM_VERTEX];

void initGraph()
{
	for(int i=0; i<NUM_VERTEX; i++)
	{
		for(int j = 0; j<NUM_VERTEX; j++)
			Graph[i][j] = 0;
	}
}

void addGraph(int v, int w)
{
	Graph[v][w] = 1;
}

void printGraph()
{
	printf(" |");
	for(int a =0 ; a<NUM_VERTEX; a++)
	{
		printf(" %d", a);
	}
	printf("\n");
	printf("ㅡㅡㅡㅡㅡㅡ\n");
	for(int i =0; i<NUM_VERTEX; i++)
	{
		printf("%d| ", i);
		
		for(int j = 0; j<NUM_VERTEX; j++)
		{
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
}

void DFS(int i)
{
	printf("%d ", i);
	visited[i] = 1;

	for(int j =0; j<NUM_VERTEX; j++)
	{
		if(!visited[j])
		{
			DFS(j);
		}
	}
}


int main()
{
	initGraph();
	
	addGraph(0,1);
	addGraph(0,2);

	addGraph(1,0);
	addGraph(1,2);

	printGraph();

	printf("Depth first Search:");
	DFS(0);
	printf("\n");
}

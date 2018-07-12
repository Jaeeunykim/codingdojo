#include <stdio.h>
#include <stdlib.h>
#define NUM_VERTEX 5

typedef struct vertex
{
	int vertex;
	struct vertex* neighbor;
}Vertex;

int visited[NUM_VERTEX];

Vertex Graph[NUM_VERTEX];

void initGraph()
{
	for(int i =0; i<NUM_VERTEX; i++)
	{
		for(int j = 0; j<NUM_VERTEX; j++)
		{
			//Graph[i][j]= 0;
			Graph[i].vertex = 0;
			Graph[i].neighbor = NULL;
		}
	}
}

void addGraph(int v, int w)
{
	//Graph[v].next 부터 시작해서 null인 것까지 찾아가기
	//w 값을 가지는 vertex 만들기
	//vertex를 붙이기
	
	Vertex* last_vertex;;
	for(last_vertex = &Graph[v]; last_vertex->neighbor != NULL; last_vertex = last_vertex->neighbor)
	{
	}

	Vertex* temp = (Vertex*)malloc(sizeof(Vertex));
	temp->vertex = w;
	temp->neighbor = NULL;
	last_vertex->neighbor = temp;

}

void printGraph()
{
	Vertex* temp;
	for(int i = 0; i<NUM_VERTEX; i++)
	{
		printf("%d |", i);
		for(temp = Graph[i].neighbor; temp != NULL; temp = temp->neighbor)
		{
			printf(" %d ", temp->vertex);
		}
		printf("\n");
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

}

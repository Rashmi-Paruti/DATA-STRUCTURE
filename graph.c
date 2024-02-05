/*
Develop a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS method
*/


#include <stdio.h>
#include <stdio.h>

const int MAX = 100;
const int SIZE = 10;
void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n);

typedef struct
{
	int iaItems[10];
	int iFront;
	int iRear;
}QUEUE;

void fnQInsert(QUEUE *stQueue, int elem);
int fnQDelete(QUEUE *stQueue);
int fnQFull(QUEUE *stQueue);
int fnQEmpty(QUEUE *stQueue);

/*
*Function	: main
*Input parameters: no parameters
*RETURNS	: 0 on success
*/
int main(void)
{
	int graph[MAX][MAX];
	int visited[MAX];
	int numVert, startVert, i,j;

	printf("Enter the number of vertices : ");
	scanf("%d", &numVert);
	printf("Enter the adjacency matrix :\n");
	for (i=0; i<numVert; i++)
		visited[i] = 0;
	for (i=0; i<numVert; i++)
		for (j=0; j<numVert; j++)
			scanf("%d", &graph[i][j]);
	printf("Enter the starting vertex : ");
	scanf("%d", &startVert);
	fnBreadthFirstSearchReach(startVert-1,graph,visited,numVert);
	printf("Vertices which can be reached from vertex %d are :-\n",startVert);
	for (i=0; i<numVert; i++)
		if (visited[i])
			printf("%d ",i+1);
	printf("\n");
	return 0;
}

/*
*Function	: fnBreadthFirstSearchReach
*Description	: Function to perform BFS traversal and mark visited vertices
*Input parameters:
*	int vertex - source vertex
*	int g[][]	- adjacency matrix of the graph
*	int v[]	- vector to store visited information
*	int n	- no of vertices
*RETURNS	: void
*/
void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n)
{
	QUEUE stQueue;
	stQueue.iFront = 0;
	stQueue.iRear = -1;
	int frontVertex, i;
	v[vertex] = 1;
	fnQInsert(&stQueue, vertex);
	while (!fnQEmpty(&stQueue))
	{
		frontVertex = fnQDelete(&stQueue);
		for (i=0; i<n; i++)
		{
			if (g[frontVertex][i] && !v[i])
			{
				v[i] = 1;
				fnQInsert(&stQueue, i);
			}
		}
	}
}

/*
*Function	: 	fnQInsert
*Description:   inserts an element at the rear of the queue
*Input parameters: a structure queue
*RETURNS	:	updated queue
*/

void fnQInsert(QUEUE *stQueue, int iItem)
{
	if(fnQFull(stQueue))
		printf("\nQueue Overflow\n");
	else
	{
		stQueue->iRear++;
		stQueue->iaItems[stQueue->iRear] = iItem;
	}
}

/*
 * *Function	: 	fnQDelete
*Description:   deletes an element from the front of the queue
*Input parameters: a structure queue
*RETURNS	:	updated queue
*/

int fnQDelete(QUEUE *stQueue)
{
	int item;
	if(fnQEmpty(stQueue))
	printf("\nQueue Underflow\n");
	else
	if(stQueue->iRear == stQueue->iFront)
	{
		item = stQueue->iaItems[stQueue->iFront];
		stQueue->iRear=-1;
		stQueue->iFront=0;
	}
	else
	{
		item = stQueue->iaItems[stQueue->iFront++];
	}
	return item;
}

/*
*Function	: 	fnQFull
*Description:   checks wheteher the queue is full or not
*Input parameters: a structure queue
*RETURNS	:	1 if the queue is full or 0 otherwise
*/
int fnQFull(QUEUE *stQueue)
{
	if(stQueue->iRear == SIZE-1)
		return 1;
	else
		return 0;
}

/*
*Function	: 	fnQEmpty
*Description:   checks wheteher the queue is empty or not
*Input parameters: a structure queue
*RETURNS	:	1 if the queue is empty or 0 otherwise
*/
int fnQEmpty(QUEUE *stQueue)
{
	if(stQueue->iRear == stQueue->iFront-1)
		return 1;
	else
		return 0;
}
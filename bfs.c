//assignment 6.1
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int size;
	int front;
	int rear;
	int *arr;
} queue;

int isEmpty(queue *q)
{
	if (q->front == q->rear)
	return (1);
	return (0);
} 
int isFull(queue *q)
{
	if (q->rear == q->size - 1)
	return (1);
	return (0);
} 
void enqueue(queue *q, int val)
{
	if (isFull(q))
	printf("\nThe queue is full");
	else
	{
	     q->rear++;
	     q->arr[q->rear] = val;
     } 
} 

int dequeue(queue *q)
{
	int a = -1;
	if (isEmpty(q))
	printf("\nThe queue is empty");
	else
	{
	q->front++;
	a = q->arr[q->front];
	} 
	return (a);
}

void main()
{
	queue q;
	q.size = 400;
	q.front = q.rear = 0;
	q.arr = (int *)malloc(q.size * sizeof(int));
	int node;
	int i = 0,j;
	int visited[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int adj[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0}};
	printf("a ");
	visited[i] = 1;
	enqueue(&q, i);
	while (!isEmpty(&q))
	{
	int node = dequeue(&q);
	for (j = 0; j < 8; j++)
	{
		if (adj[node][j] == 1 && visited[j] == 0)
		{
			printf("%c ", (char)(j+97));
			visited[j] = 1;
			enqueue(&q, j);
		}
	} 
	}
} 		

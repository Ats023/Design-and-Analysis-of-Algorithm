#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5
int minDistance(int dist[], bool mstSet[])
{

	int min = INT_MAX, min_index;
	int v;
	for ( v = 0; v < V; v++)
		if (mstSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

return min_index;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool mstSet[V];
	int i;
	for (i = 0; i < V; i++)
		dist[i] = INT_MAX, mstSet[i] = false;
	dist[src] = 0;
	int count;
	for ( count = 0; count < V - 1; count++) 
	{
		int u = minDistance(dist, mstSet);
		mstSet[u] = true;
		int v;
		for ( v = 0; v < V; v++)
			if (!mstSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}
	printf("Vertex \t\t Distance\n");
	for ( i = 0; i<V; i++)
		printf("%d \t\t %d\n", i+1, dist[i]);
}

void main()
{
	int src;
	int graph[V][V]={{0,5,2,10,6},{5,0,13,4,0},{2,13,0,9,3},{10,4,9,0,4},{6,0,3,4,0}};
	printf("Enter the source: ");
	scanf("%d", &src);
	dijkstra(graph, src-1);	
}

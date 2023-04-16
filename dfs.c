#include<stdio.h>
#include<stdlib.h>

void DFS(int *visited, int G[5][5], int i)
{
	int j;
	printf("%c ", (char)(i+65));
	visited[i]=1;
	for(j=0; j<5; j++)
	{
		if(G[i][j]==1 && !visited[j])
		DFS(visited, G, j);
	}	
}

void main()
{
	int i, j;
	int G[5][5]={{0, 1, 1, 1, 1}, 
			{1, 0, 1, 0, 0},
			{1, 1, 0, 1, 1},
			{1, 0, 1, 0, 0},
			{1, 0, 1, 0, 0}};
	int visited[5]={0,0,0,0,0};
	DFS(visited, G, 0);
}

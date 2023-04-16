#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define V 6

int find(int i);
int uni(int i, int j);
void kruskal(int matrix[V][V]);

int parent[V];
int a, b, u, v, i, j, min, mincost=0, ne=1;

int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}

int uni(int i, int j)
{
	if(i!=j) {
		parent[j]=i;
		return 1;
	}
	return 0;
}

void kruskal(int cost[V][V])
{
	printf("Edge\tCost\n");
	while(ne<V)
	{
		for(i=0, min=INT_MAX; i<V; i++)
			for(j=0; j<V; j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		u=find(u);
		v=find(v);
		if (uni(u, v))
		{
			printf("%c--%c\t%d\n", (char)(a+65), (char)(b+65), min);
			mincost+=min;
			ne++;
		}
		cost[a][b]=cost[b][a]=INT_MAX;
	}
	printf("Minimum cost: %d ", mincost);
}

void main()
{
	int i, j;
	int costMatrix[V][V] = {{0,4,5,0,0},
				{4,0,2,0,0},
				{5,2,0,0,0},
				{0,0,0,0,2},
				{0,0,0,2,0}};
	for(i=0; i<V; i++){
		for(j=0;j<V;j++) {
			if(costMatrix[i][j]==0)
			costMatrix[i][j]=INT_MAX;
		}
	}
	kruskal(costMatrix);
}

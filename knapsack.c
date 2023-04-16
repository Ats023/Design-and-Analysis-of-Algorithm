//implementation of 0/1 Knapsack
#include<stdio.h>
#include<stdlib.h>

void knapsack (int *wghs, int *profs, int n, int W)
{
    int i,j,dptable[n+1][W+1];
    for (i=0; i<=n;i++)
        for(j=0;j<=W;j++)
            if (i==0|j==0)
                dptable[i][j] = 0;
            else if (wghs[i-1]<=j)
                dptable[i][j] = (profs[i-1] + dptable[i-1][j - wghs[i-1]] > dptable[i-1][j])? profs[i-1] + dptable[i-1][j - wghs[i-1]] : dptable[i-1][j];
            else
                dptable[i][j] = dptable[i-1][j];
    
    printf("Maximum profit: %d", dptable[n][W]);
            
}

void main()
{
    int i,j,n,W,*wghs,*profs;
    printf("Number of items: ");
    scanf("%d", &n);
    printf("Max capacity: ");
    scanf("%d", &W);
    wghs=(int*)malloc(sizeof(int)*n);
    profs=(int*)malloc(sizeof(int)*n);
    printf("Weight array: ");
    for(i=0;i<n;i++)
        scanf("%d", &wghs[i]);
    printf("Profit array:");
    for(i=0;i<n;i++)
        scanf("%d", &profs[i]);
    knapsack(wghs, profs, n, W);
}

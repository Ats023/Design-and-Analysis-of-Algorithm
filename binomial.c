//Write a program to find the binomial coefficient using Dynamic programming method.
#include<stdio.h>
#include<stdlib.h>
int min(int a, int b);

void binomialCoeff (int n, int k)
{
    int i,j,dptable[n+1][k+1];
    for (i=0; i<=n;i++)
        for(j=0;j<=min(i,j);j++)
            if ((j==0) || (i==j))
                dptable[i][j] = 1;
            else 
                dptable[i][j] = dptable[i-1][j] + dptable[i-1][j-1];
    printf("The coefficient of x^%d in the expansion of (1+x)^%d is %d", k, n, dptable[n][k]);      
}

int min(int a,int b)
{
    int min = (a>b)?b:a;
    return min;
}

void main()
{
    int i,j,n,k,coeff;
    printf("Enter value of n and k: ");
    scanf("%d %d", &n, &k);
    binomialCoeff(n,k);
}

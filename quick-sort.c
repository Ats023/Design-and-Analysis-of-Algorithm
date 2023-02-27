#include<stdio.h>
#include<stdlib.h>

void swap(int*x,int i,int j)
{
	int t=x[i];
	x[i]=x[j];
	x[j]=t;
}

void quicksort(int*a,int left,int right)
{
	int i,last;
	if(left>=right)
	return;
	last = left;
	swap(a,left,(left+right)/2);
	for(i=left+1;i<=right;i++)
		if(a[left]>a[i])
			swap(a,++last,i);
	swap(a,last,left);
	quicksort(a,left,last-1);
	quicksort(a,last+1,right);	
}

void main()
{
	int *a,n;
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	printf("Enter elements of Array:\n");
	for(i=0;i<y;i++)
		scanf("%d",&x[i]);
	quicksort(a,0,n-1);
	printf("\nThe sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");	
}

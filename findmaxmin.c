//find maximum and minimum element using divide and conquer strategy

#include<stdio.h>
#include<stdlib.h>

int min (int *arr, int low, int high)
{
	int min_num, min1, min2, mid;
	if(low==high)
		min_num=arr[low];
	else if (low==high-1)
	{
		if(arr[low]>arr[high])
			min_num=arr[high];
		else
			min_num=arr[low];
	}
	else
	{
		mid=(low+high)/2;
		min1= min(arr, low, mid);
		min2= min(arr, mid+1, high);
		if (min1<min2)
			min_num=min1;
		else
			min_num=min2;
	}
	return min_num;
}
int max (int *arr, int low, int high)
{
	int max_num, max1, max2, mid;
	if(low==high)
		max_num=arr[low];
	else if (low==high-1)
	{
		if(arr[low]<arr[high])
			max_num=arr[high];
		else
			max_num=arr[low];
	}
	else
	{
		mid=(low+high)/2;
		max1= max(arr, low, mid);
		max2= max(arr, mid+1, high);
		if (max1<max2)
			max_num=max2;
		else
			max_num=max1;
	}
	return max_num;
}

void main()
{
	int i, n, max_num, min_num, *arr;
	printf("Enter the number of elements in array: ");
	scanf("%d", &n);
	arr=(int*)malloc(sizeof(int)*n);
	printf("Enter the array elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	max_num=max(arr, 0, n-1);
	min_num=min(arr, 0, n-1);
	printf("maximum number: %d\n", max_num);
	printf("minimum number: %d\n", min_num);
}

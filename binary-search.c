//binary search using divide and conquer
#include<stdio.h>
#include<stdlib.h>

int binary_search (int *arr, int low, int high, int val)
{
	int mid=(low+high)/2;
	if (low<=high)
	{
		if (arr[mid]==val)
			return mid;
		else if (arr[mid]<val)
			return binary_search(arr, mid+1, high, val);
		else if (arr[mid]>val)
			return binary_search(arr, low, mid-1, val);
	}
	else
	{
		return -1;
	}
}

void main()
{
	int i, n, val, res, *arr;
	printf("Enter the number of elements in array: ");
	scanf("%d", &n);
	arr=(int*)malloc(sizeof(int)*n);
	printf("Enter the array elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("Enter value to be searched: ");
	scanf("%d", &val);
	res=binary_search(arr, 0, n-1, val);
	if(res==-1)
		printf("Element not found\n");
	else
		printf("The element is present at index %d\n", res);

}

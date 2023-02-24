//merge sort
#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int low,int mid,int high)
{
    int i,j,k;
    int *b;
    b=(int*)malloc((high-low+1)*sizeof(int));
    i=low;
    j=mid+1;
    k=0;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
    else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=b[k];
    }
}
void mergeSort(int *a,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
	printf("The sorted array is: ");
	mergeSort(arr, 0, n-1);
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);

}

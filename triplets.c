#include<stdio.h>
#include<stdlib.h>

void triplet(int *a, int n, int *num1, int *num2, int *num3)
{
    int i=0, j=0;
    *num1=(a[i]>a[i+1])?a[i]:a[i+1]; //initialize the maximum number
    *num2=(a[i]>a[i+1])?a[i+1]:a[i]; //initialize the minimum number
    *num3=*num2;
    int max_val=(*num1 - *num2)*(*num3);
    for(i=2; i<n; i++)
    {
        *num2=(a[i]<*num2)?a[i]:*num2; //update minimum number 
        if (a[i]>=*num1) 
        {
            *num3=*num1; //take last value of maximum number as second largest
            *num1=a[i]; //update maximum number
        }
    }
}

void main()
{
    int *arr, num1, num2, num3, n, i;
	printf("Enter the number of elements in array: ");
	scanf("%d", &n);
	arr=(int*)malloc(sizeof(int)*n);
	printf("Enter the array elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	triplet(arr, n, &num1, &num2, &num3);
    printf("The triplet is %d, %d, %d\n", num1, num2, num3);
    printf("The result is (%d-%d)*%d=%d", num1, num2, num3, (num1-num2)*num3);
}
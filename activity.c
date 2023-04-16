//Given a set of ‘10’ jobs with their si and fi, find the optimal sequence of mutually compatible jobs using the greedy method: A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, si = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12} and fi = {5, 7, 8, 10, 11, 12, 13, 14, 15, 16}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
    char job_id[5];
    int start;
    int finish;
}Job;

void jobSort(Job *jobs, int n)
{
    int i,j;
    Job temp;
    for (i=0; i<n; i++)
        for(j=i+1;j<n-1;j++)
            if(jobs[i].finish>jobs[j].finish)
            {
                temp = jobs[j+1];
                jobs[j+1] = jobs[j];
                jobs[j] = temp;
            }
}

void jobSelection(Job *jobs, int n)
{
    int i = 0,j,k, count = 0;
    jobSort(jobs, n);
    printf("SEQUENCE:\n %s", jobs[i].job_id, count++);
    for (j=0;j<n;j++)
        if(jobs[j].start>=jobs[i].finish)
        {
            printf("->%s", jobs[j].job_id, count++);
            i=j;
        }
    printf("\nMaximum no. of jobs: %d", count);
}

void main()
{
    int i, n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job *jobs = (Job*)malloc(sizeof(Job)*n);
    printf("Enter job ID, start time and finish time separated by space:");
    for(i=0; i<n; i++)
        scanf("%s %d %d", &jobs[i].job_id, &jobs[i].start, &jobs[i].finish);
    jobSelection(jobs, n);
}
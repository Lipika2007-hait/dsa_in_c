/*
WAP in C to take input marks of ten students randomly in an array,
sort the array using Merge Sort and show the highest and lowest marks.
*/

#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int start,int mid,int end);
void merge_sort(int arr[],int start,int end);

void merge_sort(int arr[],int start,int end)
{
    if(start >= end)
    {
        return;
    }

    int mid=start+(end-start)/2;

    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);

    merge(arr,start,mid,end);
}

void merge(int arr[],int start,int mid,int end)
{
    int size=end-start+1;
    int *temp=(int *)malloc(size * sizeof(int));

    if(temp==NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    int left=start;
    int right=mid+1;
    int index=0;

    while(left<=mid && right<=end)
    {
        if (arr[left]<=arr[right])
        {
            temp[index++]=arr[left++];
        }
        else
        {
            temp[index++]=arr[right++];
        }
    }

    while(left<=mid)
    {
        temp[index++]=arr[left++];
    }

    while(right<=end)
    {
        temp[index++]=arr[right++];
    }

    for(int i=0;i<size;i++)
    {
        arr[start+i]=temp[i];
    }

    free(temp);
}

int main()
{
    int arr[10];

    printf("Enter marks of 10 students:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    merge_sort(arr,0,9);

    printf("\nSorted marks:\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n\nHighest Marks = %d",arr[9]);
    printf("\nLowest Marks = %d",arr[0]);

    return 0;
}
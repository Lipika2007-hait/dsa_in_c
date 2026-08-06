/*
Write a C program to take input of n numbers in an array
and sort the array in ascending order using Insertion Sort.
*/
#include<stdio.h>

void insertion_sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        int current=arr[i];
        int prev=i-1;

        while(prev>=0 && arr[prev]>current)
        {
            arr[prev+1]=arr[prev];
            prev--;
        }

        arr[prev+1]=current;
    }
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    insertion_sort(arr,n);

    printf("Sorted array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }

    return 0;
}
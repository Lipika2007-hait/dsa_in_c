/*
Question 3 (Bubble Sort):
A class teacher has a list of marks of 10 students in a random fashion. All the marks are whole numbers.
Before publishing the result, the class teacher wants to arrange the marks in ascending order so that 
the rank of the students can easily be determined. Which sorting methodology should be used? Write a C 
program to implement this method using Bubble Sort.

Sample input:[99,85,58,71,46,80,78,65,49,55]

*/

#include<stdio.h>

void swap(int i,int j,int arr[]);

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(j,j+1,arr);
         }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int i,int j,int arr[]){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int main(){

     int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int arr[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
     }
     bubble_sort(arr,n);
    return 0;
}
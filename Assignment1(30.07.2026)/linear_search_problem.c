/*
Question 1 (Linear Search):
In a library, the books are stored using access number (Acc. No.),
which is a whole number consisting of a maximum of 3 digits. Consider
an array where the access numbers of the books are stored in an unorganized
(unsorted) fashion. The librarian wants to search for a specific access number in the array.
Which searching methodology should the librarian follow? Write a C program using a function
to implement this searching technique.

Sample Input:[101,20,40,385,210,620,85,921,12,206]
Case 1:Access Number to be searched: 85
Case 2:Access Number to be searched: 465
*/

#include<stdio.h>

void linearsearch(int arr[],int n,int target){
   int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
         count++;
        }
    }
    if(count==1){
        printf("The book is avilable in this library");
    }
    else{
        printf("The book is not avilable in this library");
    }
}
int main(){
    int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int acc[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
      scanf("%d",&acc[i]);
     }
     int target;
     printf("Enter the target:");
     scanf("%d",&target);
     linearsearch(acc,n,target);
    return 0;
}
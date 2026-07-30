/*
Question 2 (Binary Search):
An online shop keeps its product catalog sorted by Product ID (whole numbers) in ascending order.
When a customer searches for a specific Product ID, the system returns True if the Product ID is present
in the catalog; otherwise,it returns False. Which searching technique is used to find the Product ID quickly 
from the catalog? Implement this searching method using a function. The function takes the Product ID list, 
the size of the list,and the Product ID to be searched as parameters.

Sample input:[2,8,9,16,18,26,38,48,51,90]
Case 1:product id to be searched:26
Case 2:product id to be searched:49
*/

#include <stdio.h>
#include<stdbool.h>

bool binarySearch(int arr[],int size,int target)
{
    int low=0;
    int high=size-1;
   
    while(low<=high)
    {
        int mid=(low+high)/2;
         if(arr[mid]==target){
           return true;  
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return false;
}


int main()
{
     int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int arr[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
     }
     int target;
     printf("Enter the target:");
     scanf("%d",&target);
     if(binarySearch(arr,n,target)){
        printf("true");
     }else{
        printf("false");
     }
    return 0;
}
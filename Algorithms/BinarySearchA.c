#include<stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x) // Check if x is present at mid
            return m;
        if (arr[m] < x) // If x greater, ignore left half
            l = m + 1;
        else
            r = m - 1; // If x is smaller, ignore right half
    }
    return -1; // If we reach here, then element was not present
}
void main()
{
    int arr[]= {1,10,20,30,40,50};
    int num;
    printf("\nEnter a number to find : ");
    scanf("%d",&num);
    int result=binarySearch(arr,0,5,num);
    if(result!=-1)
        printf("\nFound!!");
    else
        printf("\nNot Found!!");
}

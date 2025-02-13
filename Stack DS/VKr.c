#include<stdio.h>
void main()
{
    int arr[]={1,2,3,4,5};
    int arr1[4];
    int index=4;
    for(int i=0;i<5;i++)
    {
        arr1[index--]=arr[i];
    }
    for(int i=0;i<=4;i++)
    {
        printf("\n%d",arr1[i]);
    }
}

#include<stdio.h>
void getBubbleSort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[i])
            {
                arr[j]=arr[j]+arr[i];
                arr[i]=arr[j]-arr[i];
                arr[j]=arr[j]-arr[i];
            }
        }
    }
}
void main()
{
    int arr[]={64,25,5000,100,12,22,11}; //Unsorted Array
    int size=sizeof(arr)/sizeof(arr[0]);
    getBubbleSort(arr,size);
    printf("\nAscending ")
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n\nReversed Array\n");
    for(int i=size-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}

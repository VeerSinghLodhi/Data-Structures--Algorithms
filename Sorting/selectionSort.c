#include<stdio.h>
void getSelectionSort(int arr[],int size)
{
    int i,j,min_index;
    for(i=0;i<size-1;i++)
    {
        min_index=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_index])
                min_index=j;
        }
        if(min_index!=i)
        {
           arr[min_index]=arr[min_index]+arr[i];
           arr[i]=arr[min_index]-arr[i];
           arr[min_index]=arr[min_index]-arr[i];
        }
    }
}
void main()
{
    int arr[]={64,25,100,12,22,11}; //Unsorted Array
    int size=sizeof(arr)/sizeof(arr[0]);

    getSelectionSort(arr,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);//Sorted Array.
    }

}

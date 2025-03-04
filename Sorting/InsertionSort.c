#include<stdio.h>
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int currentElement = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > currentElement)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = currentElement;
    }
}
void main()
{
    int arr[]={30,20,4,5,200,300,6,70};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("\nBefore Sorting...\n\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    insertionSort(arr,size);
    printf("\n\nAfter Sorting...\n\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

#include<stdio.h>
int getSearch(int arr[],int no,int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==no)
            return i;
    }
    return -1;
}
void main()
{
    int c,arr[]={1,2,3,4,5,6,7,8};
    printf("\nEnter a number to find : ");
    scanf("%d",&c);
    int size=sizeof(arr)/sizeof(arr[0]);
    int result=getSearch(arr,c,size);
    if(result!=-1)
        printf("\nFound at index %d");
    else{
        printf("\nNot found");
    }
}

#include<stdio.h>
//int i=1;
void merge(int arr[],int s,int e){
    int mid=(s+e)/2;//mid
    int j=mid+1;
    int i=s;
    int k=s;
    int temp[s+e+1];
    while(i<=mid && j<=e)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }
}

void mergesort(int arr[],int s,int e){
  // printf("\ni is %d \n",i++);
  // getPrint(arr,6);
    if(s>=e)
        return;
    int mid=(s+e)/2;// Mid
    //printf("\n%d",mid);
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);

}
void getPrint(int arr[],int sz){
    for(int i=0;i<sz;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}
void main(){
    int arr[]={5,4,6,3,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("\nBefore Sorting...\n\n");
    getPrint(arr,size);
    //printf("\n-------------------\nProcessing...\n-------------\n");
    mergesort(arr,0,size-1);
    printf("\nAfter Sorting...\n\n");
    getPrint(arr,size);
}

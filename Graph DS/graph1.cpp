#include<iostream>
using namespace std;
int main()
{
    int n,m,num=0,i,j=0,x,y;
    cout<<"\nEnter vertices : ";
    cin>>n;
    cout<<"\nEnter Edges : ";
    cin>>m;
    int arr[n][n];
    while(num<n)
    {
        arr[num][j]=0;
        if(j>=n){
            num++;
            j=0;
        }
        else
            j++;
    }
    cout<<"\nEnter N and M :";
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        arr[x][y]=1;
    }
    for(i=0;i<n;i++)
    {
        for(int v=0;v<n;v++)
            cout<<" "<<arr[i][v];
        cout<<endl;
    }
}

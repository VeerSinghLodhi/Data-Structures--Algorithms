#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"\nEnter numbers of nodes : ";
    cin>>n;
    cout<<"\nEnter number of edges : ";
    cin>>m;
    int arr[m][m];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr[i][j]=0;
        }
    }
    for(int i=0; i<m; i++)
    {
        int u,v;
        cout<<"\nEnter U : ";
        cin>>u;
        cout<<"\nEnter V : ";
        cin>>v;
        arr[u][v]=1;
        arr[v][u]=1;
        cout<<"\nNodes Connected";
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}


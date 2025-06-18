#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data,weight;
public:
    Node(int data,int weight){
        this->data=data;
        this->weight=weight;
    }
};
class Graph{
private:
    vector<vector<Node>>adjList;
public:
    Graph(int v){
        adjList.resize(v);
    }
    void addDirectedAdge(int u,int v,int w){
        adjList[u].push_back(Node(v,w));
    }
    void addUndirectedAdge(int u,int v,int w){
        adjList[u].push_back(Node(v,w));
        adjList[v].push_back(Node(u,w));
    }
    void printGraph(){
        for(int i=0;i<adjList.size();i++){
            cout<<"\nPrinting Neighbors Node of "<<i<<" : ";
            for(auto neighbor : adjList[i]){
                cout<<"-> "<<neighbor.data<<", "<<neighbor.weight;
            }
            cout<<endl;
        }
    }
};
int main(){
    int nodes;
    cout<<"\nEnter Number of nodes : ";
    cin>>nodes;
    Graph graph(nodes);
    char direction;
    cout<<"\nDirected Or Undirected ? D/U : ";
    cin>>direction;
    if(direction=='D' || direction=='d')
    {
        for(int i=0;i<nodes;i++){
            int u,v,w;
            cout<<"\nEnter U V & W : ";
            cin>>u>>v>>w;
            graph.addDirectedAdge(u,v,w);
        }
    }else{
        for(int i=0;i<nodes;i++){
            int u,v,w;
            cout<<"\nEnter U V & W : ";
            cin>>u>>v>>w;
            graph.addUndirectedAdge(u,v,w);
        }
    }
    graph.printGraph();

}

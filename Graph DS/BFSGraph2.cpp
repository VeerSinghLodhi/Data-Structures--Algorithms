#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node(int data){
        this->data=data;
    }
};
class Graph{
private:
    vector<vector<Node>>adList;
public:
    Graph(int v){
        adList.resize(v);
    }
    void addDirected(int u,int v){
        adList[u].push_back(Node(v));
    }
    void addUndirected(int u,int v){
        adList[u].push_back(Node(v));
        adList[v].push_back(Node(u));
    }
    void getBFS(int startNode){
        cout<<endl;
        int numberOfVertices=adList.size();
        vector<bool>visited(numberOfVertices,false);
        queue<int>que;
        que.push(startNode);
        visited.at(startNode)=true;
        while(!que.empty()){
            int currentNode=que.front();
            que.pop();
            cout<<currentNode<<" ";
            for(auto neighbor : adList[currentNode]){
                if(!visited[neighbor.data]){
                    que.push(neighbor.data);
                    visited.at(neighbor.data)=true;
                }
            }
        }
        cout<<endl;
    }
    void printAdjancencyList(){
        cout<<"\n<----- Adjacency List ----->"<<endl;
        for(int i=0;i<adList.size();++i){
            cout<<"\nNeighbors Nodes of "<<i<< " : ->";
            for(auto neighbor : adList[i]){
                cout<<neighbor.data<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    cout<<"\n<----- Start Here ----->"<<endl;
    int numberOfVertices=11;
    Graph graph(numberOfVertices);
    graph.addDirected(1,2);
    graph.addDirected(1,7);
    graph.addDirected(2,3);
    graph.addDirected(2,6);
    graph.addDirected(3,4);
    graph.addDirected(6,5);
    graph.addDirected(7,8);
    graph.addDirected(7,10);
    graph.addDirected(8,9);

    graph.printAdjancencyList();
    cout<<"\n<----- BFS Traversal ----->"<<endl;
    graph.getBFS(4);

}

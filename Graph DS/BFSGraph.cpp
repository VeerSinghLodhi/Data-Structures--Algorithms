#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
void getBFS(vector<list<int>>&graph,int startNode){
    int numberOfVertices=graph.size();
    vector<bool>visited(numberOfVertices,false);
    queue<int>que;
    que.push(startNode);
    visited.at(startNode)=true;
    while(!que.empty()){
        int currentNode=que.front();
        que.pop();
        cout<<currentNode<<" ";
        for(const int neighbor : graph[currentNode]){
            if(!visited[neighbor]){
                que.push(neighbor);
                visited[neighbor]=true;
            }
        }
    }

}
int main(){

    int numberOfVertices=11;
    vector<list<int>>graph(numberOfVertices);
    graph[1].push_back(2);
    graph[1].push_back(7);
    graph[2].push_back(3);
    graph[2].push_back(6);
    graph[3].push_back(4);
    graph[6].push_back(5);
    graph[7].push_back(8);
    graph[7].push_back(10);
    graph[8].push_back(9);

    cout<<"\nGraph size : "<<graph.size()<<endl;
    cout<<"\nAdjacency Matrix : "<<endl;

    for(int i=0;i<graph.size();++i){
        cout<<"\nNeighbors nodes of - "<<i<<" : -> ";
        for(auto neighbor : graph[i]){
            cout<<neighbor<<" -> ";
        }
        cout<<endl;
    }

    cout<<"\nBFS traversal ";
    getBFS(graph,1);
}

#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;
void printAdjacencyList(vector<list<int>>graph){
    cout<<"\nAdjacency List"<<endl;
    for(int i=0;i<graph.size();i++){
        cout<<"\nNeighbors Node of "<<i<<" : ->";
        for(const int neighbor : graph[i]){
            cout<<neighbor<<" ";
        }
        cout<<endl;
    }
}
void getDFSTraversal(vector<list<int>>&graph,int startVertex){
    int numberOfVertices;
    numberOfVertices=graph.size();
    unordered_set<int>visited;
    stack<int>stk;
    stk.push(startVertex);
    visited.insert(startVertex);
    while(!stk.empty()){
        int currentVertex=stk.top();
        stk.pop();
        cout<<currentVertex<<" ";
        // Find Neighbors of Current Vertex
        for(auto it=graph[currentVertex].rbegin();it!=graph[currentVertex].rend();it++){
            int neighbor=*it;
            if(visited.find(neighbor)==visited.end()){
                stk.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}
int main(){
    int numberOfVertices=7;
    vector<list<int>>graph(numberOfVertices);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(5);
    graph[2].push_back(6);

    printAdjacencyList(graph);
    getDFSTraversal(graph,0);

}

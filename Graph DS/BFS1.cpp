#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
void bfs(vector<list<int>>&graph,int startVertex)
{
    int numVertices=graph.size();
    vector<bool>visited(numVertices,false);

    queue<int>que;
    que.push(startVertex);
    visited[startVertex]=true;

    while(!que.empty())
    {

        int current_vertex=que.front();
        que.pop();
        cout<<current_vertex<<" ";

        for(int neighbor: graph[current_vertex])
        {
            if(!visited[neighbor])
            {
                que.push(neighbor);
                visited[neighbor]=true;
            }
        }
    }

}


int main()
{
    int numVertices=6;
    vector<list<int>>graph(numVertices);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[2].push_back(0);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(5);
    graph[5].push_back(3);

    cout<<"BFS Traversal "<<endl;
    bfs(graph,0);

    return 0;
}

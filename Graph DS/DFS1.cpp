#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<stack>
using namespace std;
// Function to add an edge between two vertices
void addEdge(vector<list<int>>& graph, int src, int dest)
{
    graph[src].push_back(dest);
// For undirected graph, uncomment the following line
// graph[dest].push_back(src);
}
// Function to perform DFS traversal (iterative)
void dfsIterative(const vector<list<int>>& graph, int startVertex)
{
    unordered_set<int> visited;
    stack<int> stack;
    stack.push(startVertex);
    visited.insert(startVertex);
    while (!stack.empty())
    {
        int currentVertex = stack.top();
        stack.pop();
        std::cout << currentVertex << " ";
        for (auto it = graph[currentVertex].rbegin(); it != graph[currentVertex].rend();
                ++it)
        {
            int neighbor = *it;
            if (visited.find(neighbor) == visited.end())
            {
                stack.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}
int main()
{
// Create a graph with 6 vertices
    Graph graph(6);
// Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
// Perform DFS iterative traversal
    cout << "DFS Iterative Traversal: ";
    graph.dfsIterative(0);
    cout << endl;
    return 0;
}


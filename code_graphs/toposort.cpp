#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    vector<vector<int>> graph; // int [][]
    int n, m;
    cin >> n >> m; // Inputs the size of the graph (nodes and edges)
    graph.resize(n);
    vector<int> indegree;
    indegree.resize(n, 0);
    for (int i = 0; i < m; i++)
    {
        // Takes the edge as input
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        // Insert the edge into the graph
        graph[u].push_back(v);
        indegree[v] += 1;
    }
    // Take the element with 0 indegree
    stack<int> leaves;
    for (int node = 0; node < n; node++)
    {
        if (indegree[node] == 0)
            leaves.push(node);
    }
    // Loop over all the nodes
    for (int i = 0; i < n; i++)
    {
        // Print the output
        int current_leaf = leaves.top();
        cout << current_leaf + 1 << " ";
        leaves.pop();
        // Remove node from graph
        for (int node : graph[current_leaf]) // [2, 5, 3, 1, 9] =>  for (int i = 0; i < graph[c.size()]; i++) node = graph[c][i]
        {
            indegree[node]--;
            if (indegree[node] == 0)
                leaves.push(node);
        }
    }
    cout << "\n";
}

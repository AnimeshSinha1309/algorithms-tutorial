#include <bits/stdc++.h>
using namespace std;
#define INF 1e9


vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int s){
    int visited[graph.size()] = {0};

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(graph.size(), INF);

    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.second;

        if(visited[u] == 1) continue;
        visited[u] = 1;

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].second, w = graph[u][i].first;

            if(visited[v] == 1) continue;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    int s;
    cin >> s;

    vector<int> dist = dijkstra(graph, s);

    for(int i = 1; i <= n; i++){
        cout << "Distance from " << s << "to " << i << " is: " << dist[i] << "\n";
    }

}
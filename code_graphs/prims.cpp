#include <bits/stdc++.h>
using namespace std;

void prims(vector<vector<pair<int, int>>> &graph, int n){
    int v = 1, w = 0, sum = 0, cnt = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int visited[n + 1] = {0};

    pq.push({w, v});

    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();

        v = top.second;
        w = top.first;

        if(visited[v] == 1) continue;
        visited[v] = 1;

        sum += w;
        cnt++;

        cout << v << " " << w << "\n";

        if(cnt >= n) break;

        for(int i = 0; i < graph[v].size(); i++){
            int u = graph[v][i].second, w = graph[v][i].first;

            if(visited[u] == 1) continue;

            pq.push({w, u});
        }
    }

    cout << sum << "\n";

}


int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    prims(graph, n);

}
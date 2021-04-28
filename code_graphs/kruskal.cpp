#include <bits/stdc++.h>
using namespace std;


int find(vector<int> &parent, int u){
    if(parent[u] != u){
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void Union(vector<int> &rank, vector<int> &parent, int rootu, int rootv){
    if(rank[rootu] < rank[rootv]){
        parent[rootu] = rootv;
    }
    else if(rank[rootv] < rank[rootu]){
        parent[rootv] = rootu;
    }
    else{
        parent[rootv] = rootu;
        rank[rootu]++;
    }
}


void kruskal(vector<pair<int, pair<int, int>>> &edges, int n){
    vector<int> parent(n+1);
    vector<int> rank(n+1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end());
    
    int sum = 0, cnt = 0;

    for(int i = 0; i < edges.size(); i++){
        int w = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;

        int rootu = find(parent, u);
        int rootv = find(parent, v);

        if(rootu != rootv){
            Union(rank, parent, rootu, rootv);
            sum += w;
            cnt++;

            cout << u << " " << v << " " << w << "\n";

            if(cnt >= n-1) break;
        }
    }

    cout << sum << "\n";
}


int main(){

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    kruskal(edges, n);
}
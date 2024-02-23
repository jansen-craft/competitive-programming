#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define weight first
#define node second

vector<vector<pair<int,int>>> adj;

vector<int> djikstra(const int start, const int n){
    priority_queue<pair<int,int>> pq;
    vector<int> distance(n,INT_MAX);
    vector<bool> visited(n,false);

    distance[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int node = pq.top().node;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        for (auto neighbor: adj[node]){
            if (distance[node] + neighbor.weight < distance[neighbor.node]){
                distance[neighbor.node] = distance[node] + neighbor.weight;
                pq.push({-distance[neighbor.node], neighbor.node});
            }
        }
    }

    return distance;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,q,s,u,v,w,query;

    cin >> n >> m >> q >> s;

    while (n || m || q || s){
        adj.clear();
        adj.resize(n);

        for (int i = 0; i < m; i++){
            cin >> u >> v >> w;
            adj[u].push_back({w,v});
        }

        auto distance = djikstra(s,n);

        for (int i = 0; i < q; i++){
            cin >> query;
            if (distance[query] == INT_MAX){
                cout << "Impossible\n";
            } else {
                cout << distance[query] << '\n';
            }
        }

        cin >> n >> m >> q >> s;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> am;
vector<int> dist;
vector<bool> visited;
priority_queue<pair<int,int>> pq;

void djikstra(int start) {
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto n = pq.top();
        pq.pop();

        if(visited[n.second]) continue;
        visited[n.second] = true;

        for (int i = 0; i < am[n.second].size(); i++){
            int n_to_i = am[n.second][i];
            if(dist[n.second]+n_to_i < dist[i]){
                dist[i] = dist[n.second]+n_to_i;
                pq.push({-dist[i], i});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, parked_car, meeting_spot;
    cin >> n >> parked_car >> meeting_spot;

    am.resize(n, vector<int>(n));
    dist.resize(n, INT_MAX);
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> am[i][j];

    djikstra(parked_car);

    cout << dist[meeting_spot] << '\n';

    return 0;
}

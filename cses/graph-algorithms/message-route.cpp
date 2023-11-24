#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> previous;

void backSearch(int n){
    stack<int> s;
    s.push(n);

    while(n != 1){
        n = previous[n];
        s.push(n);
    }

    cout << s.size() << '\n';
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num_computers, num_connections;
    cin >> num_computers >> num_connections;

    adj.resize(num_computers+1, vector<int>());
    visited.resize(num_computers+1);
    previous.resize(num_computers+1, 0);

    for (int i = 0; i < num_connections; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;

    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for (auto n: adj[node]){
            if(n == num_computers){
                previous[n] = node;
                backSearch(n);
                exit(0);
            }
            if(!visited[n]){
                previous[n] = node;
                q.push(n);
                visited[n] = 1;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
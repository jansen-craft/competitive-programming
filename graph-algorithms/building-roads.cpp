#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
vector<vector<int>> adj;
vector<int> visited;
 
void dfs(int node){
    if(visited[node]) return;
    
    visited[node] = 1;
    
    for(auto n: adj[node]){
        dfs(n);
    }
}
 
int main(){
    int num_cities, num_roads;
    cin >> num_cities >> num_roads;
    
    adj.resize(num_cities+1, vector<int>());
    visited.resize(num_cities+1, 0);
    
    for (int i = 0; i < num_roads; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    
    queue<pair<int,int>> q;
    
    for (int i = 1; i <= num_cities; i++) {
        if(!visited[i]){
            q.push(pair<int,int>(1,i));
            dfs(i);
        }
    }
    
    cout << q.size() << '\n';
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        cout << p.first << ' ' << p.second << '\n';
    }
 
    return 0;
}

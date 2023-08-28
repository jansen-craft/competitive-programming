#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> previous;

void printCycle(int starting_node){

    stack<int> s;
    s.push(starting_node);
    int n = -1;
    n = previous[starting_node];
    s.push(n);
    while(n != starting_node){
        n = previous[n];
        s.push(n);
    }

    cout << s.size() << '\n';
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << '\n';
}

void dfs(int node){
    visited[node] = 1;

    for (auto a: adj[node]){
        if(visited[a] && a != previous[node]){
            previous[a] = node;
            printCycle(a);
            exit(0);
        } else if(!visited[a]){
            previous[a] = node;
            dfs(a);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num_cities, num_roads;

    cin >> num_cities >> num_roads;

    adj.resize(num_cities+1, vector<int>());
    visited.resize(num_cities+1, 0);
    previous.resize(num_cities+1, -1);

    for (int i = 0; i < num_roads; i++){
        int city_a, city_b;
        cin >> city_a >> city_b;
        adj[city_a].push_back(city_b);
        adj[city_b].push_back(city_a);
    }

    dfs(1);

    for (int i = 1; i <= num_cities; i++)
        if(!visited[i]) dfs(i);

    cout << "IMPOSSIBLE\n";

    return 0;
}
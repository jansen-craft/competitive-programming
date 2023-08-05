#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> depth;

int count_children(int index){
    if(tree[index].size() == 0){
        return 0;
    }
    for (size_t i = 0; i < tree[index].size(); i++){
        depth[index] += 1 + count_children(tree[index][i]);
    }
    return depth[index];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    tree.resize(n+1);
    depth.resize(n+1, 0);

    for (int i = 2; i <= n; i++){
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    count_children(1);

    for (int i = 1; i <= n; i++)
        cout << depth[i] << '\n';

    return 0;
}
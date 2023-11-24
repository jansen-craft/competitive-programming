#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int room_num = 0;

void search(int row, int col){
    graph[row][col] = room_num;

    // search up
    if (graph[row+1][col] == -1) {
        search(row+1, col);
    }
    // search right
    if (graph[row][col+1] == -1) {
        search(row, col+1);
    }
    // search left
    if (graph[row][col-1] == -1) {
        search(row, col-1);
    }
    // search down
    if (graph[row-1][col] == -1) {
        search(row-1, col);
    }
}
    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int rows, cols;
    cin >> rows >> cols;

    graph.resize(rows+2, vector<int>(cols+2, 0));

    for (int i = 1; i <= rows; i++){
        string entry;
        cin >> entry;
        for (int j = 1; j <= cols; j++)
            graph[i][j] = entry.at(j-1) == '.' ? -1 : 0;
    }

    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= cols; j++){
            if(graph[i][j] == -1) {
                room_num++;
                search(i, j);
            }
        }
    }

    cout << room_num << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

char DIRECT[4] = {'D','R','U','L'};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<char>> graph;
    vector<vector<int>> prev;
    int rows, cols;
    pair<int, int> start, end;
    queue<pair<int,int>> q;
    string ans = "";

    cin >> rows >> cols;

    graph.resize(rows+2, vector<char>(cols+2, '#'));
    prev.resize(rows+2, vector<int>(cols+2, -1));

    for (int i = 0; i < rows; i++){
        string r;
        cin >> r;
        for (int j = 0; j < cols; j++){
            graph[i+1][j+1] = r.at(j);
            if(r.at(j) == 'A') {
                start = make_pair(i+1,j+1);
                graph[i+1][j+1] = '.';
            }
            if(r.at(j) == 'B') {
                end = make_pair(i+1,j+1);
                graph[i+1][j+1] = '.';
            }
        }
    }

    q.push(start);

    while(!q.empty()){
        pair<int,int> cell = q.front();
        q.pop();

        for (size_t i = 0; i < 4; i++){
            pair<int,int> new_cell = make_pair(cell.first + dx[i],cell.second + dy[i]);
            if(graph[new_cell.first][new_cell.second] == '.'){
                graph[new_cell.first][new_cell.second] = '#';
                prev[new_cell.first][new_cell.second] = i;
                if(new_cell == end){
                    q = {};
                    
                    while(end != start){
                        int rev_dir = prev[end.first][end.second];
                        int dir = (rev_dir + 2) % 4;
                        end.first += dx[dir];
                        end.second += dy[dir];
                        ans.push_back(DIRECT[rev_dir]);
                    }

                    reverse(ans.begin(), ans.end());
                    cout << "YES\n";
                    cout << ans.size() << '\n';
                    cout << ans << '\n';

                    return 0;
                }
                q.push(new_cell);
            }
        }
    }

    cout << "NO\n";

    return 0;
}
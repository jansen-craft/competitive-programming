#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

const int M =  1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n; cin.ignore();
    vector<vector<int>> board(n+1,vector<int>(n+1));
    vector<vector<int>> moves(n+1,vector<int>(n+1,0));

    for (int i = 1; i <= n; i++){
        string t;
        getline(cin, t);
        for (int j = 1; j <= n; j++){
            if(t[j-1] == '.'){
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }

    moves[1][0] = 1;
    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(board[i][j]) moves[i][j] = (moves[i-1][j] + moves[i][j-1]) % M;
    
    cout << moves[n][n] << '\n';
    
    return 0;
}

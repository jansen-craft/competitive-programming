#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int board_size, frog, magic_number, jumps = 0;
    vector<int> board;
    vector<bool> visited;

    cin >> board_size >> frog >> magic_number;
    board.resize(board_size+1);
    visited.resize(board_size+1, false);

    for (int i = 1; i <= board_size; i++)
        cin >> board[i];    

    while(true){
        if(frog < 1) {
            cout << "left\n" << jumps << '\n';
            exit(0);
        } else if(frog > board_size) {
            cout << "right\n" << jumps << '\n';
            exit(0);
        } else if (board[frog] == magic_number){
            cout << "magic\n" << jumps << '\n';
            exit(0);
        } else if (visited[frog] == true){
            cout << "cycle\n" << jumps << '\n';
            exit(0);
        }

        visited[frog] = true;

        frog += board[frog];
        jumps++;
    }

    return 0;
}

#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

const long long M = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, max_tower = 0;
    cin >> n;
    vector<long long> query(n);

    for(int i = 0; i < n; i++){
        cin >> query[i];
        max_tower = max(max_tower, query[i]);
    }

    vector<vector<long long>> towers(2,vector<long long>(max_tower+1, 0));
    vector<long long> total(max_tower+1, 0);

/*
    0   #of ┏━━━┓   ┏━━━┓
            ┗━━━┛   ┃   ┃

    1   #of ┏━┳━┓   ┏━┳━┓   ┏━┳━┓   ┏━┳━┓
            ┗━┻━┛   ┃ ┃ ┃   ┗━┻ ┃   ┃ ┗━┛ 
*/

    towers[0][1] = 1;
    towers[1][1] = 1;

    for(int i = 2; i <= max_tower; i++){
        // 0 -> (2) 0s -> 0 & 1, (1) 1s -> 2
        towers[0][i] = ((towers[0][i] % M) + ((2*(towers[0][i-1] % M)) % M)) % M;
        towers[1][i] = ((towers[1][i] % M) + (towers[0][i-1] % M)) % M;
        // 1 -> (1) 0s -> 0, (4) 1s -> 2 3 4 5
        towers[0][i] = ((towers[0][i] % M) + (towers[1][i-1] % M)) % M;
        towers[1][i] = ((towers[1][i] % M) + ((4*(towers[1][i-1] % M)) % M)) % M;
    }

    for (int j = 0; j <= max_tower; j++)
        for(int i = 0; i < 2; i++)
            total[j] = ((total[j] % M) + (towers[i][j] % M)) % M;

    for(auto q: query)
        cout << total[q] << '\n';
    
    return 0;
}


// const int M = 1000000007;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, max_tower = 0;
//     cin >> n;
//     vector<int> query(n);

//     for(int i = 0; i < n; i++){
//         cin >> query[i];
//         max_tower = max(max_tower, query[i]);
//     }

//     vector<vector<int>> towers(6,vector<int>(max_tower+1, 0));

//     vector<int> total(max_tower+1, 0);

// /*
//     0   #of ┏━━━┓
//             ┗━━━┛

//     1   #of ┏━━━┓
//             ┃   ┃

//     2   #of ┏━┳━┓
//             ┗━┻━┛

//     3   #of ┏━┳━┓
//             ┃ ┃ ┃

//     4   #of ┏━┳━┓
//             ┗━┻ ┃

//     5   #of ┏━┳━┓
//             ┃ ┗━┛    
// */

//     towers[0][1] = 1;
//     towers[2][1] = 1;

//     for(int i = 2; i <= max_tower; i++){
//         // 0
//         towers[0][i] += towers[0][i-1];
//         towers[1][i] += towers[0][i-1];
//         towers[2][i] += towers[0][i-1];

//         // 1
//         towers[0][i] += towers[1][i-1];
//         towers[1][i] += towers[1][i-1];
//         towers[2][i] += towers[1][i-1];

//         // 2
//         towers[0][i] += towers[2][i-1];
//         towers[2][i] += towers[2][i-1];
//         towers[3][i] += towers[2][i-1];
//         towers[4][i] += towers[2][i-1];
//         towers[5][i] += towers[2][i-1];

//         // 3
//         towers[0][i] += towers[3][i-1];
//         towers[2][i] += towers[3][i-1];
//         towers[3][i] += towers[3][i-1];
//         towers[4][i] += towers[3][i-1];
//         towers[5][i] += towers[3][i-1];
//         // 4
//         towers[0][i] += towers[4][i-1];
//         towers[2][i] += towers[4][i-1];
//         towers[3][i] += towers[4][i-1];
//         towers[4][i] += towers[4][i-1];
//         towers[5][i] += towers[4][i-1];

//         // 5
//         towers[0][i] += towers[5][i-1];
//         towers[2][i] += towers[5][i-1];
//         towers[3][i] += towers[5][i-1];
//         towers[4][i] += towers[5][i-1];
//         towers[5][i] += towers[5][i-1];
//     }
    
//     // cout << '\t';
//     // for (int j = 0; j <= max_tower; j++){
//     //         cout << '\t' << j;
//     //     }
//     // cout << "\n\n";
//     // for (int i = 0; i < 6; i++){
//     //     cout << i << '\t';
//     //     for (int j = 0; j <= max_tower; j++){
//     //         cout << '\t' << towers[i][j];
//     //     }
//     //     cout << '\n';
//     // }

//     for (int j = 0; j <= max_tower; j++){
//         for(int i = 0; i < 6; i++){ 
//             total[j] = ((total[j] % M) + (towers[i][j] % M)) % M;
//         }
//     }

//     for(auto q: query){
//         cout << total[q] << '\n';
//     }
    
//     return 0;
// }

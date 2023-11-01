#include <iostream>
#include <iomanip>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

vector<vector<int>> d(11, vector<int>(11, 1));

vector<int> cost(10000, 0);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Build distances
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++){
            d[i][j] += abs(j - i);
        }
    }

    // Build cost
    for (int i = 0; i < 10; i++){
        int k1 = i == 0 ? 10 : i;
        for (int j = 0; j < 10; j++){
            int k2 = j == 0 ? 10 : j;
            for (int k = 0; k < 10; k++){
                int k3 = k == 0 ? 10 : k;
                for (int l = 0; l < 10; l++){
                    int location = i*1000 + j*100 + k*10 + l;
                    int k4 = l == 0 ? 10 : l;

                    cost[location] = d[1][k1] + d[k1][k2] + d[k2][k3] + d[k3][k4];
                }
            }
        }
    }

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        string input;
        cin >> input;
        int location = (input[0]-'0')*1000 + (input[1]-'0')*100 + (input[2]-'0')*10 + (input[3]-'0');
        cout << cost[location] << '\n';
    }

    return 0;
}

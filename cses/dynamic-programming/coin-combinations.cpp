//#include <iostream>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, g;
    cin >> n >> g;

    vector<int> coins(n);
    vector<int> combos(g+1);
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    combos[0] = 1;
    for (int i = 1; i <= g; i++)
        for (auto coin : coins)
            if (i-coin >= 0) combos[i] = (combos[i] + combos[i-coin]) % M;
    
    cout << combos[g] << '\n';
    
    return 0;
}

/*

    0 1 2 3 4 5 6 7 8 9 (i)

0   1 0 0 0 0 0 0 0 0 0
2     0 1 0 1 1 1 3 2 5
3     0 1 1 1 2 2 4 5 7
5     0 1 1 1 3 2 5 6 8

*/


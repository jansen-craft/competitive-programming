#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, g;
    cin >> n >> g;
    vector<int> coins(n);

    for(int i = 0 ; i < n; i++)
        cin >> coins[i];
    
    vector<long long> combos(g+1);
    combos[0] = 1;
    for (auto coin: coins)
        for (int i = coin; i <= g; i++)
            combos[i] = (combos[i-coin] + combos[i]) % M;
    
    cout << combos[g] << '\n';
    
    return 0;
}

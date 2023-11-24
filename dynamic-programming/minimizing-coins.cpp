#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;

    vector<int> coins(n);
    vector<int> count(d+1, INT_MAX);
    count[0] = 0;

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    for(auto c: coins)
        for (int i = c; i <= d; i++){
            if(count[i-c] != INT_MAX){
                count[i] = min(count[i], 1+count[i-c]);
            }
        }

    // for(int i = 0; i <= d; i++){
    //     cout << i << '\t' << count[i] << '\n';
    // }

    if(count[d] == INT_MAX){
        cout << "-1\n";
    } else {
        cout << count[d] << '\n';
    }

    return 0;
}

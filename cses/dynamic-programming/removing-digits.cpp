#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> jumps(n+1,INT_MAX);
    jumps[0] = 0;

    for (int i = 1; i <= n; i++){
        int j = i;
        do {
            int digit = j % 10;
            if (i-digit >= 0 && jumps[i-digit] != INT_MAX){
                jumps[i] = min(jumps[i], jumps[i-digit]+1);
            }
        } while (j /= 10);
    }
    
    cout << jumps[n] << '\n';
    return 0;
}



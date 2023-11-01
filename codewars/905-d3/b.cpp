#include <iostream>
#include <vector>
#include <iomanip>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        vector<int> count (26,0);

        int n, k;
        string input;
        cin >> n >> k >> input;

        for(auto c: input) count[c-'a']++;

        int odd_count = 0;
        for(auto c: count)
            if (c % 2 == 1) odd_count++;

        int r = odd_count - k;

        if (r <= 1){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

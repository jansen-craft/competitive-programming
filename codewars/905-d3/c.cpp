#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int j = 0; j < v.size(); j++)
            v[j] = v[j] % k;

        int mx = *max_element(v.begin(), v.end());
        int mn = *max_element(v.begin(), v.end());

        if (mn == 0) {
            cout << 0 << '\n';
            exit(0);
        }

        cout << (k - mx) % 5 << '\n';
        
    }
    
    return 0;
}

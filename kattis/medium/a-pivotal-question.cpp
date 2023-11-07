#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> valid(n, true);
    for (size_t i = 0; i < n; i++)
        cin >> v[i];
    
    // max left
    int mx = 0;
    for (int i = 0; i < n; i++){
        if(v[i] > mx){
            mx = v[i];
        } else {
            valid[i] = false;
        }
    }

    // min right
    int mn = INT_MAX;
    for (int i = n-1; i >= 0; i--){
        if(v[i] < mn){
            mn = v[i];
        } else {
            valid[i] = false;
        }
    }

    vector<int> valid_list;
    for (int i = 0; i < n; i++)
        if(valid[i])
            valid_list.push_back(v[i]);
    
    cout << valid_list.size();
    for (int i = 0; i < valid_list.size() && i < 100; i++)
        cout << ' ' << valid_list[i];
    cout << '\n';
    
    return 0;
}

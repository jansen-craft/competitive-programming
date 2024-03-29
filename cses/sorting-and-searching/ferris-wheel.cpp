#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, l, limit, total = l = 0;
    cin >> r >> limit;
    vector<int> w(r);

    for (int i = 0; i < r; i++){
        cin >> w[i];
    }
    
    sort(w.begin(), w.end());
    r--;
    
    while(r > l){
        if(w[r] != limit && w[r] + w[l] <= limit){
            l++;
        }
        total++;
        r--;
        if(r == l){
            total++;
        }
    }
    cout << total;
    return 0;
}

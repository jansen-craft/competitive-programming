#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> duration;
    vector<int> survival;

    int n, time_to_drink;
    cin >> n >> time_to_drink;
    duration.resize(n);
    survival.resize(n);
    for (int i = 0; i < n; i++)
        cin >> duration[i];
    
    sort(duration.begin(), duration.end(), greater<int>());

    for (int i = 0; i < n; i++)
        survival[i] = duration[i] - (((n-1)-i) * time_to_drink);

    bool valid = true;
    for (int i = 0; i < n; i++)
        if(survival[i] < 1) valid = false;

    if(valid) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
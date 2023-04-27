#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp;
    long long total = 0, sum = 0;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> tmp;
        sum += tmp;
        v[((sum % n) + n) % n]++;   // handles negative mod
    }

    for (int i = 0; i < n; i++){
        long long a = v[i];
        if(a > 1){
            total += (a * (a - 1)) / 2; // // add number choose 2
        }
    }

    total += v[0];

    cout << total;

    return 0;
}

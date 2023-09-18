#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int m = 1000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> w(n+1);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    w[n] = INT_MAX;

    long long sum = 0;
    for (int i = n-1; i >= 0; i--){
        if(w[i] >= w[i+1]){
            int lost = w[i] - w[i+1] + 1;
            sum += lost;
            w[i] -= lost;
        }

        if(w[i] <= 0 && w[i+1] <= 0){
            cout << "1\n";
            exit(0);
        }
    }

    cout << sum << '\n';


    

    return 0;
}

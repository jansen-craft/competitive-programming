#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> count(n+1);
    count[0] = 1;

    for(int i = 0; i <= n; i++)
        for(int j = 1; j <= 6; j++)
            if(i - j >= 0) count[i] = (count[i] + count[i-j]) % M;

    cout << count[n] << '\n';
    return 0;
}

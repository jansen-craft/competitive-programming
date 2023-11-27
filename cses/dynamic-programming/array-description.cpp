#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

const long long M = 1000000007;

#define low first
#define high second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    vector<vector<long long>> total(n+1, vector<long long>(m+2, 0));

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    // Initialize for first number
    if(v[1]){
        total[1][v[1]] = 1;
    } else {
        for (int j = 1; j <= m; j++)
            total[1][j] = 1;
    }
    
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (v[i] == j || (!v[i] && !(v[i+1] && (j < v[i+1]-1 || j > v[i+1]+1)))) // sorry about this
                total[i][j] = (((total[i-1][j-1] + total[i-1][j]) % M) + total[i-1][j+1]) % M;

    int sum = 0;
    for(auto e: total[n])
        sum = (sum + e) % M;
    
    cout << sum << '\n';
    return 0;
}

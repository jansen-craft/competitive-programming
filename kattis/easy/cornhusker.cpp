#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(10);
    int n, kwf, total = 0;
    for (int i = 0; i < 10; i++)
        cin >> v[i];
    cin >> n >> kwf;
    
    for (int i = 0; i < 10; i+=2)
        total += v[i] * v[i+1];

    cout << ((total/5) * n)/kwf << '\n';
    
    return 0;
}

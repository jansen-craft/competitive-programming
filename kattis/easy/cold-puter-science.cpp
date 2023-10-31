#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int count = count_if(v.begin(), v.end(), [](int x){return x < 0;});
    
    cout << count << '\n';
    return 0;
}

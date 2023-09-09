#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(3);

    for (int i = 0; i < 3; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    string order;
    cin >> order;
    for (int i = 0; i < 3; i++)
        cout << v[order[i]-'A'] << ' ';

    cout << '\n';
    
    

    return 0;
}
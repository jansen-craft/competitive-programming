#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long k, m ,n;
    cin >> k >> m >> n;

    bool alexWins = ((k % (m+n)) >= m);
    if (alexWins){
        cout << "Alex\n";
    } else {
        cout << "Barb\n";
    }

    return 0;
}

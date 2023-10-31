#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b){
    if (b == 0) return a;
    return gcd (b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int p, q, s;
    cin >> p >> q >> s;

    if ((p * q) / gcd(p, q) <= s){
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    return 0;
}

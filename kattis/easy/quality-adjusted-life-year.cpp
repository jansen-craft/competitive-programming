#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    double sum = 0.0;
    for (int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        sum += (a*b);
    }
    
    cout << sum << '\n';

    return 0;
}

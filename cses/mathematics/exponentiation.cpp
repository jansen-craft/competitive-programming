#include <bits/stdc++.h>
using namespace std;

int MODULO = 1000000007;

long long modular_power(int base, int exponent){
    long long Y = 1;
    long long Z = base;
    int N = exponent;

    Z = Z % MODULO; 

    if (Z == 0) return 0;

    while (N > 0){
        if (N & 1) Y = (Y * Z) % MODULO;
        N = N / 2;
        Z = (Z * Z) % MODULO;
    }

    return Y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, number, power;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> number >> power;
        if(power == 0){
            cout << 1 << '\n';
        } else {
            cout << modular_power(number, power) << '\n';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long p_10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000};
long long num_9[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999, 9999999999999};

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // left of decimal, right of decimal, P length
    ll I, p_length;
    string rod;

    cin >> I;
    cin.ignore(1);
    cin >> rod >> p_length;

    ll P = stoll(rod) % p_10[p_length];
    ll A = stoll(rod) / p_10[p_length];
    ll a_length = rod.length() - p_length;

    ll IA = I * p_10[a_length] + A;
    ll IAP = IA * p_10[p_length] + P;

    ll numerator = IAP - IA;
    ll denominator = num_9[p_length] * p_10[a_length];

    // simplify
    ll gcd_nm = gcd(numerator, denominator);
    numerator /= gcd_nm;
    denominator /= gcd_nm;    

    cout << numerator << '/' << denominator << '\n';

    return 0;
}
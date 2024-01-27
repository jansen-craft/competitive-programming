#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double b;
    int k,g;
    cin >> b >> k >> g;
    b-= 1.0;
    cout << ceil(b / (k/g)) << '\n';
    return 0;
}
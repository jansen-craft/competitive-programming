#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        P p1 = {x1, y1};
        P p2 = {x2, y2};
        P p3 = {x3, y3};

        ll result = (conj(p3-p1)*(p3-p2)).Y;

        if(result < 0){
            cout << "RIGHT\n";
        } else if(result == 0) {
            cout << "TOUCH\n";
        } else {
            cout << "LEFT\n";
        }
    }

    return 0;
}
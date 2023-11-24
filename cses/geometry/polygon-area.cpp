#include <bits/stdc++.h>
using namespace std;

typedef complex<long long> P;
#define X real()
#define Y imag()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, area = 0;
    vector<P> verticies;
    
    cin >> n;
    verticies.resize(n+1);

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        verticies[i] = P(x,y);
    }

    verticies[n] = verticies[0];

    for (int i = 0; i < n; i++){
        area += (conj(verticies[i])*(verticies[i+1])).Y;
    }

    cout << abs(area) << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <complex>
#include <algorithm>
#include <set>
#include <limits>
#include <iomanip>

using namespace std;

#define l first
#define r second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, total = 0;
    cin >> n;
    vector<pair<int,int>> v(n+1);
    for (int i = 1; i <= n; i++)
        cin >> v[i].l >> v[i].r;

    for (int i = 1; i < n; i++){
        // Check if i work with the next two
        bool _0_1 = (v[i].l <= i+1 && v[i].r >= i+1) && (v[i+1].l <= i && v[i+1].r >= i);
        bool _1_2 = (v[i+1].l <= i+2 && v[i+1].r >= i+2) && (v[i+2].l <= i+1 && v[i+2].r >= i+1);
        bool _2_0 = (v[i+2].l <= i && v[i+2].r >= i) && (v[i].l <= i+2 && v[i].r >= i+2);
        if (_0_1 && _1_2 && _2_0) {
            i += 2;
            total++;
        }
    }

    cout << total << '\n';

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pair<int,string> a = {0,"Monnei"}, b = {0,"Fjee"}, c = {0,"Dolladollabilljoll"};
    cin >> a.first >> b.first >> c.first;
    auto best = min({a,b,c});
    cout << best.second << '\n';

    return 0;
}
#include <iostream>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    
    int x = count_if(s.begin(), s.end(), [](char c){return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';});
    int y = count(s.begin(), s.end(), 'y');

    cout << x << ' ' << x+y << '\n';

    return 0;
}
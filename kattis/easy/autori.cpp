#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, valid = "";
    cin >> s;
    for (size_t i = 0; i < s.length(); i++)
        if(s[i] >= 'A' && s[i] <= 'Z') valid.push_back(s[i]);
    
    cout << valid << '\n';
    return 0;
}

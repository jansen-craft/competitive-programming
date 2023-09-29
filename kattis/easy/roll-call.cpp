#include <iostream>
#include <map>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tmp, first, last;
    vector<pair<string,string>> names;
    unordered_map<string, int> fn;

    while(cin >> tmp){
        first = tmp;
        cin >> last;
        names.push_back({last, first});
        fn[first]++;
    }

    sort(names.begin(), names.end());

    for (int i = 0; i < names.size(); i++){
        cout << names[i].second;
        if(fn[names[i].second] > 1) cout << ' ' << names[i].first;
        cout << '\n';
    }
    
    return 0;
}

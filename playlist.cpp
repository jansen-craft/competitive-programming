#include <iostream>
#include <vector>
#include <set>
//#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num_songs, r = 0, l = 0, max = 0;
    set<int> s;
    cin >> num_songs;
    vector<int> v(num_songs);

    for (int i = 0; i < num_songs; i++){
        cin >> v[i];
    }

    while(r < num_songs){
        if(s.count(v[r]) == 0){
            s.insert(v[r]);
        } else {
            if(r-l > max){
                max = r-l;
            }
            while(v[l] != v[r]){
                s.erase(v[l]);
                l++;
            }
            l++;
        }
        r++;
    }
    if(r-l > max){
        max = r-l;
    }

    cout << max;

    return 0;
}

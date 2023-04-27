#include <iostream>
#include <set>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<int> rd;
    multiset<int> dist;

    int length, num_lights, tmp, max;
    cin >> length >> num_lights;

    rd.insert(0);
    rd.insert(length);
    dist.insert(length);

    for (int i = 0; i < num_lights; i++){
        cin >> tmp;

        rd.insert(tmp);         // add to rd set
        auto pt = rd.find(tmp);

        auto left = pt;
        left--;

        auto right = pt;
        right++;

        dist.erase(dist.find(*right - *left));  // update distances
        dist.insert(*right - *pt);
        dist.insert(*pt - *left);

        max = *(--dist.end());      // update max distance
        if(i != 0)
            cout << ' ';
        cout << max;
    }
    
    return 0;
}

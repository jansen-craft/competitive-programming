#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k, l, u, c, total, as_index, ds_index = total = as_index = 0;
    vector<int> desired_size;
    vector<int> apartment_size;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++){
        cin >> l;
        desired_size.push_back(l);
    }

    for (int i = 0; i < m; i++){
        cin >> l;
        apartment_size.push_back(l);
    }

    sort(apartment_size.begin(), apartment_size.end());
    sort(desired_size.begin(), desired_size.end());
    
    while(as_index < m && ds_index < n){
        l = desired_size[ds_index] - k;
        u = l + k + k;
        c = apartment_size[as_index];

        if(c >= l && c <= u){
            as_index++;
            ds_index++;
            total++;
        } else if(c < l){
            as_index++;
        } else {
            ds_index++;
        }
    }   
    
    cout << total << endl;
    return 0;
}

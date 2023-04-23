#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m, k, total=0, as_index=0, ds_index=0;
    cin >> n >> m >> k;
    vector<int> desired_size(n);
    vector<int> apartment_size(m);
 
    for (int i = 0; i < n; i++){
        cin >> desired_size[i];
    }
 
    for (int i = 0; i < m; i++){
        cin >> apartment_size[i];
    }
 
    sort(apartment_size.begin(), apartment_size.end());
    sort(desired_size.begin(), desired_size.end());
    
    while(as_index < m && ds_index < n){ 
        if(apartment_size[as_index] >= (desired_size[ds_index] - k) && apartment_size[as_index] <= (desired_size[ds_index] + k)){
            as_index++;
            ds_index++;
            total++;
        } else if(apartment_size[as_index] < (desired_size[ds_index] - k)){
            as_index++;
        } else {
            ds_index++;
        }
    }   
    
    cout << total << endl;
    return 0;
}

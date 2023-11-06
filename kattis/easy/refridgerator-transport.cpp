#include <iostream>
#include <iomanip>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int cost_a, cap_a, cost_b, cap_b, n;
    cin >> cost_a >> cap_a >> cost_b >> cap_b >> n;
    
    int d = n/cap_a + 1;
    vector<int> b_trips(d);
    vector<int> cost(d);
    
    for (int i = 0; i < d; i++){
        int leftover = n - (i * cap_a);

        int trips_by_b = leftover % cap_b == 0 ? leftover / cap_b : (leftover / cap_b) + 1;
        int cost_of_b = trips_by_b * cost_b;
        
        b_trips[i] = trips_by_b;
        cost[i] = (i * cost_a) + cost_of_b;
    }
    
    int m = d-1;
    for (int i = 0; i < d; i++){
        if(cost[i] < cost[m]) m = i;
    }

    cout << m << ' ' << b_trips[m] << ' ' << cost[m] << '\n';
    return 0;
}

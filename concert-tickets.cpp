#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_tickets, num_customers;
    cin >> num_tickets >> num_customers;

    vector<int> ticket_price (num_tickets);
    vector<int> max_price (num_customers);

    for (int i = 0; i < num_tickets; i++){
        cin >> ticket_price[i];
    }

    for (int i = 0; i < num_customers; i++){
        cin >> max_price[i];
    }

    sort(ticket_price.begin(), ticket_price.end());
    
    for (int c = 0; c < num_customers; c++){
        auto l = upper_bound(ticket_price.begin(), ticket_price.end(), max_price[c]);
        
        if(l == ticket_price.begin()){
            cout << -1 << endl;
        } else {
            l--;
            cout << *l << endl;
            ticket_price.erase(l);
        }
    }
    
    return 0;
}

#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_tickets, num_customers, t, c;
    cin >> num_tickets >> num_customers;
    vector<int> ticket_price (num_tickets);
    vector<int> max_price {num_customers};

    for (int i = 0; i < num_tickets; i++){
        cin >> ticket_price[i];
    }

    for (int i = 0; i < num_customers; i++){
        cin >> max_price[i];
    }

    sort(ticket_price.begin(), ticket_price.end());
    sort(max_price.begin(), max_price.end());
    
    c = num_customers;
    for (int c = num_customers - 1; c >= 0; c--){

    }
    
    
    
    return 0;
}

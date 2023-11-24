#include <iostream>
#include <set>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_tickets, num_customers, tmp;
    cin >> num_tickets >> num_customers;

    multiset<int> m;

    for (int i = 0; i < num_tickets; i++){
        cin >> tmp;
        m.insert(tmp);
    }

    for (int i = 0; i < num_customers; i++){
        cin >> tmp;
        auto p = m.upper_bound(tmp);
        if(p == m.begin()){
            cout << "-1 ";
        } else {
            p--;
            cout << *p << ' ';
            m.erase(p);
        }

    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<string, set<int>> stores_with_item;
    vector<string> purchases;

    int supermarkets, items, items_purchased;
    cin >> supermarkets >> items;
    for (int i = 0; i < items; i++){
        int store;
        string item;
        cin >> store >> item;
        stores_with_item[item].insert(store);
    }

    cin >> items_purchased;
    purchases.resize(items_purchased);
    for (int i = 0; i < items_purchased; i++)
        cin >> purchases[i];
    
    // Find min route from left to right
    int minimum_valid_store = 0;
    for (int i = 0; i < items_purchased; i++){
        string item = purchases[i];

        // Remove stores below minimum valid store
        vector<int> bad_stores;
        for (auto store: stores_with_item[item])
            if (store < minimum_valid_store) bad_stores.push_back(store);
        
        for (auto bad_store: bad_stores)
            stores_with_item[item].erase(bad_store);

        // New minumum is largest number between min in set and minimum valid
        if(stores_with_item[item].size() > 0)
            minimum_valid_store = max(*stores_with_item[item].begin(), minimum_valid_store);
    }

    // Find max route from right to left
    int maximum_valid_store = INT_MAX;
    for (int i = items_purchased-1; i >= 0; i--){
        string item = purchases[i];

        // Remove stores above maximum valid store
        vector<int> bad_stores;
        for (auto store: stores_with_item[item])
            if (store > maximum_valid_store) bad_stores.push_back(store);
        
        for (auto bad_store: bad_stores)
            stores_with_item[item].erase(bad_store);
        
        // New maximum is smallest number between max in set and maximum valid
        if(stores_with_item[item].size() > 0)
            maximum_valid_store = min(*stores_with_item[item].rbegin(), maximum_valid_store);    
    }

    bool valid = true;
    bool unique = true;

    for (auto item: purchases){
        if (stores_with_item[item].size() == 0)valid = false;
        if (stores_with_item[item].size() > 1)unique = false;
    }

    if (valid && unique){
        cout << "unique\n";
    }  else if(valid && !unique) {
        cout << "ambiguous\n";
    } else {
        cout << "impossible\n";
    }

    return 0;
}
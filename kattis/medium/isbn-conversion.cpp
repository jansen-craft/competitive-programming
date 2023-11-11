#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> isbn;

bool is_valid(int num){
    string isbn_10 = isbn[num];
    vector<int> ns;

    int total_hyphens = 0;
    int last_hyphen = -1;

    for (int i = 0; i < isbn_10.size(); i++){
        if(isbn_10[i] >= '0' && isbn_10[i] <= '9'){
            ns.push_back(isbn_10[i]-'0');
        } else if (i == isbn_10.size() - 1 && isbn_10[i] == 'X'){
            ns.push_back(10);
        } else if (isbn_10[i] == '-'){
            // cannot begin or end with hyphen
            if(i == 0 || i == isbn_10.size()-1) return false;
            // no consecutive hyphens
            if(i - last_hyphen == 1) return false;
            total_hyphens++;
            last_hyphen = i;
        }
    }
    // three hyphens max
    if(total_hyphens > 3) return false;

    // if three hyphens - must have hyphen before ending
    if(total_hyphens == 3 && isbn_10[isbn_10.size()-2] != '-') return false;

    // must be length 10
    if (ns.size() != 10) return false;

    int res = 0;
    for (int i = 0; i < ns.size(); i++)
        res += (10-i) * ns[i];
    // if checksum doesn't workout
    if (res % 11 != 0) return false;

    return true;
}

string convert(int x){
    string isbn_10 = isbn[x];
    vector<int> ns;
    vector<int> hyphen_positions;

    for (int i = 0; i < isbn_10.size(); i++){
        if(isbn_10[i] >= '0' && isbn_10[i] <= '9'){
            ns.push_back(isbn_10[i]-'0');
        } else if (i == isbn_10.size() - 1 && isbn_10[i] == 'X'){
            ns.push_back(10);
        } else if(isbn_10[i] == '-'){
            hyphen_positions.push_back(i);
        }
    }

    // cout << "10 ->\t\t";
    // for (auto num: ns)
    //     cout << num << ' ';
    // cout << '\n';

    string isbn_13 = "978-"+isbn_10.substr(0,isbn_10.size()-1);

    int total = 38;
    for (int i = 0; i < ns.size()-1; i++){
        if(i % 2 == 0){
            // 1
            total += (3*ns[i]);
        } else {
            // 3
            total += ns[i];
        }
    }

    int rem = total % 10;
    int checks = 0;
    if(rem != 0){
        checks = 10 - (total % 10);
    }
    isbn_13 += char(checks + '0');

    // cout << "13 ->\t\t";
    // cout << isbn_13;
    // cout << '\n';

    return isbn_13;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    isbn.resize(n);
    for (int i = 0; i < n; i++)
        cin >> isbn[i];
    
    for (int i = 0; i < n; i++){
        if(is_valid(i)){
            cout << convert(i) << '\n';
        } else {
            cout << "invalid\n";
        }
    }
    
    return 0;
}

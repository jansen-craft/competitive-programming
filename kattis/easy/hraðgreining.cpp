#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

const string GOAL = "COV";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    if(s.find(GOAL) != string::npos){
        cout << "Veikur!\n";
    } else {
        cout << "Ekki veikur!\n";
    }
    return 0;
}

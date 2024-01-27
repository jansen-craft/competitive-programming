#include <iostream>
#include <sstream>
#include <string>
//#include <bits/stdc++.h>

using namespace std;

string encode (string s){
    char cur_char;
    int cur_len = 1;
    string output = "";

    for (size_t i = 0; i < s.length(); i++){
        if(i == 0) {
            cur_char = s[i];
            continue;
        }
        if (s[i] == cur_char){
            cur_len++;
        } else {
            output.push_back(cur_char);
            output += to_string(cur_len);
            cur_char = s[i];
            cur_len = 1;
        }
    }
    output.push_back(cur_char);
    output += to_string(cur_len);
    
    return output;
}

string decode (string s){
    stringstream ss (s);
    string output = "";
    char c;
    int i;

    while (ss >> c){
        ss >> i;
        string addition (i, c);
        output += addition;
    }

    return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string c, input;
    cin >> c >> input;
    if (c == "E"){
        cout << encode(input) << '\n';
    } else {
        cout << decode(input) << '\n';
    }
    return 0;
}

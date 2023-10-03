#include <iostream>
#include <list>
//#include <bits/stdc++.h>

using namespace std;

void squish(string& program, vector<int> &v){
    int front_removed = 0;
    int back_removed = 0;
    bool front = 1;

    for (int i = 0; i < program.length(); i++){
        if(program[i] == 'R'){
            front = !front;
        } else if(program[i] == 'D'){
            if (front){
                front_removed++;
            } else {
                back_removed++;
            }
        }
    }

    if(front_removed + back_removed > v.size()){
        cout << "error\n";
    } else {
        cout << '[';
        if(front){
            for (int i = front_removed; i < (v.size()-back_removed); i++){ // forwards
                if (i != front_removed) cout << ',';
                cout << v[i];
            }
        } else {
            for (int i = (v.size()-(back_removed+1)); i >= front_removed; i--){ // backwards
                if (i != (v.size()-(back_removed+1))) cout << ',';
                cout << v[i];
            }
        }
        cout << "]\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        vector<int> v;
        string program;
        int list_n;

        cin >> program;
        cin >> list_n;
        v.resize(list_n);

        cin.ignore();
        for (int j = 0; j < list_n; j++){
            cin.ignore();
            cin >> v[j];
        }
        cin.ignore();

        if(list_n == 0) cin.ignore();

        // Solve
        int front_removed = 0;
        int back_removed = 0;
        bool front = true;

        for (int i = 0; i < program.length(); i++){
            if(program[i] == 'R'){
                front = !front;
            } else if(program[i] == 'D'){
                if (front){
                    front_removed++;
                } else {
                    back_removed++;
                }
            }
        }

        if(front_removed + back_removed > v.size()){
            cout << "error\n";
        } else {
            cout << '[';
            if(front){
                for (int i = front_removed; i < (v.size()-back_removed); i++){ // forwards
                    if (i != front_removed) cout << ',';
                    cout << v[i];
                }
            } else {
                for (int i = (v.size()-(back_removed+1)); i >= front_removed; i--){ // backwards
                    if (i != (v.size()-(back_removed+1))) cout << ',';
                    cout << v[i];
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}

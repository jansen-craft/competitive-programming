#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<string, bool> s;

    int parts, days, replaced = 0;
    cin >> parts >> days;

    for (int i = 1; i <= days; i++){
        string new_part;
        cin >> new_part;
        if(s[new_part] != true) {
            s[new_part] = true;
            replaced++;
        }

        if(replaced == parts){
            cout << i << '\n';
            exit(0);
        }
    }

    cout << "paradox avoided\n";
    

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n,l;
    string a,b,st,_, result = "0";
    cin >> n >> l;
    unordered_map<string,int> idx;
    vector<string> status(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a >> st;
        idx[a] = i;
        status[i] = st;
    }
    
    vector<int> look(n,-1);
    for (int i = 0; i < l; i++) {
        cin >> a >> _ >> b;
        look[idx[a]] = idx[b];
        string ab = status[idx[a]] + status[idx[b]];
        if (ab == "m?" || ab == "?u" || ab == "??") result = "?";
    }

    vector<bool> visited (n,false);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && status[i] == "m"){
            int cur = i;
            visited[cur] = true;
            while (cur != -1 && !visited[look[cur]]){
                cur = look[cur];
                visited[cur] = true;
                if (status[cur] == "u") result = "1";
            }
        }
    }
    
    cout << result << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, min_val, max_val;
    cin >> n >> min_val >> max_val;
    vector<int> v(n);
    for (size_t i = 0; i < n; i++)
        cin >> v[i];

    bool found_min = find(v.begin(), v.end(), min_val) != v.end();
    bool found_max = find(v.begin(), v.end(), max_val) != v.end();
    
    if (found_min && found_max){
        for(int i = min_val; i <= max_val; i++)
            cout << i << '\n';
    } else if (found_min && !found_max){
        cout << max_val << '\n';
    } else if (!found_min && found_max){
        cout << min_val << '\n';
    } else {
        cout << "-1\n";
    }
    
    return 0;
}
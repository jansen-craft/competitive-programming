#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, lph, time = 5;
    cin >> n >> lph;
    time *= lph;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int num_problems = 0;
    for (int i = 0; i < n; i++){
        if (time - v[i] < 0) break;
        time -= v[i];
        num_problems++;
    }
    
    cout << num_problems << '\n';
    
    return 0;
}
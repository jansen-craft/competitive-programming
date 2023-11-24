#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, highest_num = -1;
    vector<int> v;
    vector<int> divisors;

    cin >> n;
    v.resize(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    // Get largest number for buildiung seive
    for (int i = 0; i < n; i++)
        highest_num = max(highest_num, v[i]);

    divisors.resize(highest_num+1, 0);

    // Add array elements to seive
    for (int i = 0; i < n; i++)
        divisors[v[i]]++;

    // Starting at end of seive and going down, count how many multiples are found going up
    for (int i = highest_num; i > 0; i--){
        int j = i;
        int count = 0;
        while (j <= highest_num){
            if(divisors[j] > 1) {
                cout << j << '\n';
                return 0;
            } else if (divisors[j] == 1){
                count++;
            }

            j += i;

            if(count == 2){
                cout << i << '\n';
                return 0;
            }
        }
    }

    return 0;
}
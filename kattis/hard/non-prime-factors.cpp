#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 2000001;
    
vector<int> seive (MAX_NUM+1, 0);
vector<int> factors (MAX_NUM+1, 1);
vector<int> num_pf (MAX_NUM+1, 0);
vector<int> npf (MAX_NUM+1);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // N log n-ish
    for (size_t i = 2; i < MAX_NUM; i++){
        if(seive.at(i)) continue;

        for (long j = 2*i; j < MAX_NUM; j += i){
            seive.at(j) = i;

            int l = j;
            int f = i;

            int count = 0;
            while(l % f == 0){
                count++;
                l /= f;
            }

            factors[j] *= count+1;
            num_pf[j]++;
        }
    }

    for (int i = 0; i < MAX_NUM; i++){
        npf[i] = factors[i] - num_pf[i];
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        cout << npf[num] << '\n';
    }
    
    return 0;
}
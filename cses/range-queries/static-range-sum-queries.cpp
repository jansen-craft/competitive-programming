#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int num_v, num_q;
    cin >> num_v >> num_q;
    vector<long long> values(num_v + 1);
    vector<long long> prefix_sum(num_v + 1);
    prefix_sum[0] = 0;

    for (int i = 1; i <= num_v; i++){
        cin >> values[i];
        prefix_sum[i] = prefix_sum[i-1] + values[i];
    }    

    for (int i = 0; i < num_q; i++){
        int begin, end;
        cin >> begin >> end;
        cout << prefix_sum[end] - prefix_sum[begin] + values[begin] << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, divisor;
    long long pairs = 0;
    vector<int> v;
    unordered_map<int, long long > visited;
    unordered_map<int, long long> q_count;

    cin >> n >> divisor;
    
    v.resize(n);
    for (int  i = 0; i < n; i++)
        cin >> v[i];

    for (int  i = 0; i < n; i++){
        long long  q = v[i] / divisor;
        visited[q]++;

        if(visited[q] == 2){
            q_count[q] = 1;
            pairs++;
        } else if (visited[q] > 2){
            pairs -= q_count[q];
            long long count_choose_2 = ((visited[q] - 1) * visited[q]) / 2;
            q_count[q] = count_choose_2;
            pairs += q_count[q];
        }
    }

    cout << pairs << '\n';

    return 0;
}

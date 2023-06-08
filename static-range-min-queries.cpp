#include <bits/stdc++.h>
using namespace std;

int log2(long long num){
    if(num == 0){
        return 0;
    }
    int log_2 = 0;
    while (num >>= 1) ++log_2;
    return log_2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long num_values, num_queries;
    cin >> num_values >> num_queries;
    vector<long long> values(num_values+1);
    vector<vector<int>> preprocess(num_values+1, vector<int> (num_values+1)); 

    //read inputs
    for (int i = 0; i < num_values; i++){
        cin >> values[i];
        preprocess[i][0] = values[i];
    }

    // pre-process
    for (int j = 1; j < log2(num_values) + 1; j++)
        for (int i = 0; i < num_values - (1<<j) + 1; i++)
            preprocess[i][j] = min(preprocess[i][j-1], preprocess[i+(1<<(j-1))][j-1]);

    // respond to each query
    for (int i = 0; i < num_queries; i++){
        long long begin, end, length, size;
        cin >> begin >> end;
        length = end - begin + 1;
        size = 0;
        while((1<<(size+1)) <= length) size++;
        long long result = min(preprocess[begin-1][size], preprocess[end-1-(1<<size)+1][size]);
        cout << result << '\n';
    }

    return 0;
}
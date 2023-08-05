#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num_nums, number;
    
    cin >> num_nums;
    for (int i = 0; i < num_nums; i++){
        cin >> number;

        vector<int> prime_factors;
        for (int x = 2; x*x <= number; x++){
            while(number%x== 0){
                prime_factors.push_back(x);
                number /= x;
            }
        }

        if(number > 1) prime_factors.push_back(number);
        
        int num_factors = 1;
        int last_num = -1;
        int cur_total = 0;

        for (auto pf: prime_factors){
            if(pf != last_num){
                num_factors *= (cur_total+1);
                cur_total = 1;
            } else {
                cur_total++;
            }
            last_num = pf;
        }
        num_factors *= (cur_total+1);
        
        cout << num_factors << '\n';
    }
    

    return 0;
}
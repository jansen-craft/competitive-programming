#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // This is a horrible solution. Please don't use this as a reference

    for (int i = 0; i < n; i++){
        int first_base, second_base;
        string num, source, target;
        unordered_map<char, int> source_bit;
        cin >> num >> source >> target;
        
        for (size_t i = 0; i < source.length(); i++)
            source_bit[source[i]] = i;

        first_base = source.length();
        second_base = target.length();

        int num_b_10 = 0;
        int power = 0;
        for (int j = (int)num.length()-1; j >= 0; j--){
            int number = source_bit[num[j]];
            num_b_10 += number * (int)pow(first_base, power);
            power++;
        }

        string converted_number = "";
        
        int start_power = 0;
        while(pow(second_base, start_power) <= num_b_10) start_power++;
        start_power--;

        for (int p = start_power; p >= 0; p--){
            int b = (int)pow(second_base, p);
            int digit = num_b_10 / b;
            num_b_10 -= (digit * b);
            converted_number.push_back(target[digit]);
        }
        
        cout << "Case #" << i+1 << ": " << converted_number << "\n"; 
    }
    

    return 0;
}
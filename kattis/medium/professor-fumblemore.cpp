#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

unsigned long long p2[64] = {
    1ULL,
    2ULL,
    4ULL,
    8ULL,
    16ULL,
    32ULL,
    64ULL,
    128ULL,
    256ULL,
    512ULL,
    1024ULL,
    2048ULL,
    4096ULL,
    8192ULL,
    16384ULL,
    32768ULL,
    65536ULL,
    131072ULL,
    262144ULL,
    524288ULL,
    1048576ULL,
    2097152ULL,
    4194304ULL,
    8388608ULL,
    16777216ULL,
    33554432ULL,
    67108864ULL,
    134217728ULL,
    268435456ULL,
    536870912ULL,
    1073741824ULL,
    2147483648ULL,
    4294967296ULL,
    8589934592ULL,
    17179869184ULL,
    34359738368ULL,
    68719476736ULL,
    137438953472ULL,
    274877906944ULL,
    549755813888ULL,
    1099511627776ULL,
    2199023255552ULL,
    4398046511104ULL,
    8796093022208ULL,
    17592186044416ULL,
    35184372088832ULL,
    70368744177664ULL,
    140737488355328ULL,
    281474976710656ULL,
    562949953421312ULL,
    1125899906842624ULL,
    2251799813685248ULL,
    4503599627370496ULL,
    9007199254740992ULL,
    18014398509481984ULL,
    36028797018963968ULL,
    72057594037927936ULL,
    144115188075855872ULL,
    288230376151711744ULL,
    576460752303423488ULL,
    1152921504606846976ULL,
    2305843009213693952ULL,
    4611686018427387904ULL,
    9223372036854775808ULL,
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    bool valid = true;
    cin >> s;

    // Check for final O
    if(s.at(s.length()-1) != 'O') valid = false;

    int num_e = count(s.begin(), s.end(), 'E');
    int num_o = count(s.begin(), s.end(), 'O');

    // Check for non E/O
    if (num_e + num_o < s.length()) valid = false;

    // Check for double Os
    for (int i = 1; i < s.size(); i++)
        if (s[i] == 'O' && s[i-1] == 'O')
            valid = false;
    
    if(!valid){
        cout << "INVALID\n";
        exit(0);
    }


    // Find smallest value of n that works
    unsigned long long min_valid = ULLONG_MAX;
    for (int i = 2; i <= 63; i++){
        unsigned long long num = p2[i];
        bool valid = true;

        for (int j = s.length()-1; j >= 0; j--){
            if (s[j] == 'E' && (num&(-num)) != num){
                // E & not power of 2
                // *2
                num *= 2;
            } else if (s[j] == 'O' && (num - 1) % 3 == 0){
                // O & num -1 is a multiple of 3
                // -1 / 3
                num = (num -1) / 3;
            } else {
                // Invalid
                valid = false;
                break;
            }
        }
        
        if (valid){
            //cout << num << "\t[" << i << "]\n";
            min_valid = min(min_valid, num);
        }
    }
    
    cout << min_valid << "\n";
    
    return 0;
}

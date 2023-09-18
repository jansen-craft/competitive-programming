#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> words(n+1);
    unordered_map<string, int> last_seen;

    for (int i = 1; i <= n; i++)
        cin >> words[i];

    int min_distance_between_equal_words = n;

    for (int i = 1; i <= n; i++){
        string current_word = words[i];

        if(last_seen[current_word]){ // If you've seen this word before
            min_distance_between_equal_words = min(min_distance_between_equal_words, i-last_seen[current_word]);
        }

        last_seen[current_word] = i;
    }

    int longest_identifiable_song_subsequence = n - min_distance_between_equal_words;

    cout << longest_identifiable_song_subsequence << '\n';

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define team_id first
#define school_id second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, c;
    cin >> n >> k >> c;

    vector<pair<int,int>> v(n);
    vector<pair<int,int>> qualified(k);
    unordered_map<int,int> school_count;
    unordered_map<int,bool> used;

    for (int i = 0; i < n; i++)
        cin >> v[i].team_id >> v[i].school_id;
    
    int num_qualified = 0;
    for (int i = 0; i < n && num_qualified < k; i++){
        auto team = v[i];
        if(school_count[team.school_id] < c){
            qualified[num_qualified] = {i, team.team_id};
            school_count[team.school_id]++;
            used[team.team_id] = true;
            num_qualified++;
        }
    }

    // Grab best extra teams
    if (num_qualified < k){
        for (int i = 0; i < n && num_qualified < k; i++){
            auto team = v[i];
            if (!used[team.team_id]){
                qualified[num_qualified] = {i, team.team_id};
                used[team.team_id] = true;
                num_qualified++;
            }
        }
    }

    sort(qualified.begin(), qualified.end());

    for(auto team: qualified)
        cout << team.second << '\n';
    
    return 0;
}
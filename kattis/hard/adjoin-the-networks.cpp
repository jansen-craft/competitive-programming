#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> al;
vector<vector<bool>> visited;

int num_computers, l;

pair<int,int> farthest(int start, int iteration){
    stack<pair<int, int>> s;
    int max_distance = 0;
    int max_node = start;
    int n;
    s.push({start, 0});

    while(!s.empty()){
        n = s.top().first;
        int d = s.top().second;
        s.pop();
        visited[iteration][n] = true;

        if(d > max_distance){
            max_distance = d;
            max_node = n;
        }

        for (size_t i = 0; i < al[n].size(); i++)
            if (!visited[iteration][al[n][i]]) s.push({al[n][i], d+1});
    }

    return {max_node, max_distance};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> num_computers >> l;
    al.resize(num_computers);

    // Build adjacency list
    for (int i = 0; i < l; i++){
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    visited.resize(2, vector<bool>(num_computers, false));

    int first_diameter = -1;
    int second_diameter = -1;
    int third_diameter = -1;

    // Calculate diameters
    for (int i = 0; i < num_computers; i++){
        if(!visited[0][i]){
            int i_farthest = farthest(i, 0).first;
            auto diameter_i = farthest(i_farthest, 1).second;
            
            // Really efficient and genius ranking system:
            if (diameter_i > first_diameter){
                third_diameter = second_diameter;
                second_diameter = first_diameter;
                first_diameter= diameter_i;
            } else if (diameter_i > second_diameter){
                third_diameter = second_diameter;
                second_diameter = diameter_i;
            } else if (diameter_i > third_diameter){
                third_diameter = diameter_i;
            }
        }
    }

    int bonus = 1;
    int result;

    if (first_diameter == second_diameter && second_diameter == third_diameter){
        bonus = 2;
    }
    
    int first_jumps = first_diameter % 2 == 0 ? first_diameter / 2 : first_diameter / 2 + 1;
    int second_jumps = second_diameter % 2 == 0 ? second_diameter / 2 : second_diameter / 2 + 1;
    result = max({first_diameter, second_diameter, first_jumps + second_jumps + bonus});
    
    cout << result << '\n';

    return 0;
}

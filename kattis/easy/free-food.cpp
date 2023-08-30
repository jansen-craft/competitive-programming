#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> c (366, 0);
    vector<int> length_one (366, 0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        c[start]++;
        c[end]--;

        if(start == end){
            length_one[start] = 1;
        }
    }

    int sum = 0;
    int count = 0;

    for (int i = 1; i <= 365; i++){
        count += c[i];

        if(c[i] < 0 || c[i] > 0){
            sum++;
        } else if (c[i] == 0){            
            if(count > 0) {
                sum++;
            } else if( length_one[i] == 1){
                sum++;
            }
        }
    }
    
    cout << sum << '\n';
    
    return 0;
}

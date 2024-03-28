#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,a,b;
    cin >> n;
    vector<int> added(n+1,0);
    for (int i = 0; i <= n/2; i++){
        cin >> a >> b;
        added[a]++;
        added[b]++;
    }
    
    for(int i = 1; i <= n; i++)
        if (added[i] > 1)
            cout << i << ' ';
            
    return 0;
}

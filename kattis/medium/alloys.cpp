#include <iostream>
using namespace std;
typedef long double ld;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ld n;
    cin>>n;
    n=min(n,(ld)1.0);
    cout<<(n/2)*(n/2)<<'\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef complex<long long> P;
#define X real()
#define Y imag()

bool intersect(P A, P B, P C, P D){
    // common vertex
    bool common_vertex = (A == C) || (A == D) || (B == C) || (B == D);
    if (common_vertex) {
        return true;
    }

    // on same line
    bool same_line = ((conj(C-A)*(C-B)).Y == 0) && ((conj(D-A)*(D-B)).Y == 0);
    if(same_line) {
        vector<P> points = {A,B,C,D};
        sort(points.begin(), points.end(), [](P p1, P p2) {return p1.X < p2.X;});

        if((points[0] == A && points[1] != B) || (points[0] == B && points[1] != A)){
            return true;
        } else if((points[0] == C && points[1] != D) || (points[0] == D && points[1] != C)){
            return true;
        }

        sort(points.begin(), points.end(), [](P p1, P p2) {return p1.Y < p2.Y;});

        if((points[0] == A && points[1] != B) || (points[0] == B && points[1] != A)){
            return true;
        } else if((points[0] == C && points[1] != D) || (points[0] == D && points[1] != C)){
            return true;
        }

        return false;
    }

    // If A & B are on different sides of the line that crosses C & D && vice versa
    bool cd_on_different_sides = ((conj(C-A)*(C-B)).Y >= 0 && (conj(D-A)*(D-B)).Y <= 0) || ((conj(C-A)*(C-B)).Y <= 0 && (conj(D-A)*(D-B)).Y >= 0);
    bool ab_on_different_sides = ((conj(A-C)*(A-D)).Y >= 0 && (conj(B-C)*(B-D)).Y <= 0) || ((conj(A-C)*(A-D)).Y <= 0 && (conj(B-C)*(B-D)).Y >= 0);
    if (cd_on_different_sides && ab_on_different_sides) {
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        P A = {x1, y1};
        P B = {x2, y2}; 
        P C = {x3, y3}; 
        P D = {x4, y4};

        bool intersection = intersect(A, B, C, D);

        if(intersection) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

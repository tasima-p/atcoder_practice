# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
# define rep(i,n) drep(i,0,n-1)
# define sz(s) (int)(s.size())
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A;
    rep(i,n){
        rep(j,n){
            int x;
            cin >> x;
            A[i].push_back(x);
        }
    }
    int m;
    pair<int,int> XY;
    cin >> m;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        XY.first = x;
        XY.second = y;
    }

    return 0;
}
# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> G(n+1);
  rep(i, m){
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  drep(i,1,n+1){
    cout << i << ": {";
    rep(j, sz(G[i])){
      cout << G[i][j];
      if (j + 1 != sz(G[i])) cout << ", ";
    }
    cout << "}" << endl;
  }
  return 0;
}
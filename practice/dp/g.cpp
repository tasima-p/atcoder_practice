# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

vector<int> memo;
vector<vector<int>> G;

int recursion(int i){
  if (memo[i] != -1) return memo[i];
  
  if(G[i].empty()){
    memo[i] = 0;
    return 0;
  }

  int imax = 0;
  for(auto v: G[i]){
    chmax(imax,recursion(v) + 1);
  }

  memo[i] = imax;
  return imax;
}

int main() {
  int n,m;
  cin >> n >> m;

  G.resize(n);

  rep(i,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
  }

  memo.resize(n);
  rep(i,n){
    memo[i] = -1;
  }
  int max = 0;
  rep(i,n){
    chmax(max,recursion(i));
  }

  cout << max;
  return 0;
}
# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

int n,w;
vector<long long> W(110);
vector<long long> V(110);

vector<vector<long long>> dp(110, vector<long long>(110000));

int main() {
  cin >> n >> w;
  rep(i,n){
    cin >> W[i] >> V[i];
  }

  rep(i,n+1){
    rep(j,sz(dp[i])){
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;

  rep(i,n){
    rep(j,sz(dp[i])){
      chmin(dp[i+1][j], dp[i][j]);
      chmin(dp[i+1][j+ V[i]], dp[i][j] + W[i]);
    }
  }

  long long ans = INF;
  rep(i,110000){
    if (dp[n][i] <= w) ans = i; 
  }

  cout << ans;
  return 0;
}
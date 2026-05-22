# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmai(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

long long mod = 1000000007;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char> (w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }

  vector<vector<long long>> dp(h, vector<long long> (w,0));

  dp[0][0] = 1;

  rep(i,h){
    rep(j,w){
      if (i + 1 < h && a[i + 1][j] != '#'){
        dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
      }
      if (j + 1 < w && a[i][j + 1] != '#'){
        dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
      }
    }
  }

  cout << dp[h-1][w-1] % mod;

  return 0;
}
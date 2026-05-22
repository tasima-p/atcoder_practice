# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

int n;

vector<vector<long long>> abc(110000, vector<long long>(3));

vector<vector<long long>> dp(110000, vector<long long>(3));

int main() {
  cin >> n;
  rep(i,n){
    cin >> abc[i][0] >> abc[i][1] >> abc[i][2];
  }

  rep(i,n){
    rep(j,3){
      dp[i][j] = 0;      
    }
  }

  rep(i,n+1){
    rep(j,3){
      rep(k,3){
        if(j == k) continue;
        chmax(dp[i+1][j], dp[i][k] + abc[i][k]);
      }
    }
  }

  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

  return 0;
}
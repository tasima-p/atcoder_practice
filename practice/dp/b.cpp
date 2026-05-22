# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

int main(){
  int n,k;
  vector<long long> h(110000);
  cin >> n >> k;
  rep(i,n) cin >> h[i];


  vector<long long> dp(110000);
  rep(i,sz(dp)) dp[i] = INF;
  dp[0] = 0;

  rep(i,n){
    drep(j,1,k+1){
      chmin(dp[i+j],dp[i]+abs(h[i]-h[i+j]));
    }
  }

  cout << dp[n-1] << endl;
}


// int main() {
//   int n,k;
//   cin >> n >> k;

//   vector<int> H(n);
//   rep(i,n) cin >> H[i];
//   vector<int> dp(n);

//   if (n < k){
//     k = n;
//   }

//   dp[0] = 0;
//   drep(i,1,k){
//     vector<int> cost;
//     drep(j,1,i+1){
//       cost.push_back(abs(H[i] - H[i-j]));
//     }
//     auto it = min_element(cost.begin(), cost.end());
//     int min = *it;
//     int index = i - (distance(cost.begin(), it) + 1);

//     dp[i] = dp[index] + min;
//   }


//   drep(i,k,n){
//     vector<int> cost;
//     drep(j,1,k+1){
//       cost.push_back(abs(H[i] - H[i-j]));
//     }
//     auto it = min_element(cost.begin(), cost.end());
//     int min = *it;
//     int index = i - (distance(cost.begin(), it) + 1);
//     dp[i] = dp[index] + min;
//   }

//   cout << dp[n-1];
//   return 0;
// }
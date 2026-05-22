# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

int main() {
  int x;
  cin >> x;
  if (x < 3 || 18 < x){
    cout << "No";
  }else{
    cout << "Yes";
  }
  return 0;
}
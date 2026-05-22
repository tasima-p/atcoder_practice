# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

int main() {
  string s;
  cin >> s;
  char last = s[0];
  long long cnt1=1;
  long long ans = 0;
  drep(i,1,sz(s)){
    if(last ==  s[i]){
      ans += (cnt1*(cnt1+1)/2);
      cnt1 = 1;
    }else{
      cnt1 += 1;
    }
    last = s[i];
  }
  ans += (long long)(cnt1*(cnt1+1)/2);
  cout << ans % 998244353 << endl;
  return 0;
}
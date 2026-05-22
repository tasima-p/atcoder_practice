# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
# define rep(i,n) drep(i,0,n-1)
# define sz(s) (int)(s.size())
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 0){
    return;
  }
  vector<string> A;
  rep(i,n){
    rep(j,n){
      A[i].insert(j,"()");
    }
  }

  return 0;
}
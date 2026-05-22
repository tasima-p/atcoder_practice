# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
# define rep(i,n) drep(i,0,n-1)
# define sz(s) (int)(s.size())
using namespace std;

int main() {
  int n, l, k;
  vector<int> a;
  cin >> n >> l >> k;
  int x,y;
  rep(i,n){
    cin >> x;
    if (i > 0){
      a.push_back(x - y); 
    }else{
      a.push_back(x);
    }
    y = x;
  }
  a.push_back(l - y);

  int ok = -1, ng = l + 1;
  while(ng - ok > 1){
    int mid = (ok + ng) / 2;

    int cnt = 0, length = 0;
    rep(i,n+1){
      length += a[i];

      if (length >= mid){
        cnt++;
        length = 0;
      }
    }

    if (cnt >= k+1){
      ok = mid;
    }
    else {
      ng = mid;
    }
  }

  cout << ok ;

  return 0;
}
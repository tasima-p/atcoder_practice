// https://atcoder.jp/contests/abc128/tasks/abc128_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(m);
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k){
      int a;
      cin >> a;
      a--;
      s[i].push_back(a);
    }
  }
  vector<int> p(m);
  rep(i, m) cin >> p[i];

  ll ans = 0;
  // bit全探索
  for (int bit = 0; bit < (1 << n); bit++){
    bool ok = true;
    for (int i = 0; i < m; i++){
      int cnt = 0;
      for (int j : s[i]){
        if (bit & (1 << j)) cnt++;
      }
      if (cnt % 2 != p[i]) ok = false;
    }
    if (ok) ans++;
  }
  cout << ans << endl;
}
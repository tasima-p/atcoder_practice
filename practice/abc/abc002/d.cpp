// https://atcoder.jp/contests/abc002/tasks/abc002_4
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  // n*nの隣接行列
  vector<vector<int>> connection(n, vector<int>(n));

  rep(i, n) {
    rep(j, n) {
      connection[i][j] = 0;
    }
  }
  rep(i, m) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    connection[x][y] = 1;
    connection[y][x] = 1;
  }


  int ans = 1;
  for (int bit = 0; bit < (1 << n); bit++){
    vector<int> including;
    for (int i = 0; i<n; i++){
      if(bit & (1 << i)){
        including.push_back(i);
      }
    }
    int size = including.size();
    if (size == 0) continue;

    bool ok = true;
    for (int i = 0; i<size; i++){
      for (int j = i+1; j < size; j++){
        if (connection[including[i]][including[j]] != 1){
          ok = false;
        }
      }
    }
    if (ok) ans = max(ans,size);
  }
  cout << ans << endl;
}
# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  queue<int> q;
  vector<int> visited(n,-1);
  q.push(0);
  visited[0] = 1;
  while (!q.empty())
  {
    int current = q.front();
    q.pop();

    for(auto v: G[current]){
      if(visited[v] != -1) continue;
      q.push(v);
      visited[v] = 1;
    }
  }

  rep(i,n){
    if(visited[i] == -1){
      cout << "The graph is not connected.";
      return 0;
    }
  }

  cout << "The graph is connected.";
  
  return 0;
}
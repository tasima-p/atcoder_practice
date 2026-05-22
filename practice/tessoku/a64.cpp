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
  vector<vector<pair<int,int>>> G(n);
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].push_back(make_pair(b,c));
    G[b].push_back(make_pair(a,c));
  }

  vector<int> correct(n,0);
  vector<long long> dist(n,INF);
  priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
  dist[0] = 0;
  q.push(make_pair(0,0));

  while(!q.empty()){
    int current = q.top().second;
    q.pop();

    if (correct[current] == 1) continue;

    correct[current] = 1;

    for(auto x: G[current]){
      int next = x.first;
      int l = x.second;
      if (dist[current] + l < dist[next]){
        dist[next] = dist[current] + l;
        q.push(make_pair(dist[next],next));
      }
    }
  }

  rep(i,n){
    if (dist[i] >= INF / 2) {
      cout << -1 << endl;
    } else {
      cout << dist[i] << endl;
    }
  }

  return 0;
}
# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
# define rep(i,n) drep(i,0,n-1)
# define sz(s) (int)(s.size())
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> adj(n + 1);
  rep(i,n - 1){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // bfs
  vector<int> explored1(n + 1, -1);
  queue<int> queue1;
  explored1[1] = 0;
  queue1.push(1);
  while (!queue1.empty())
  {
    int current = queue1.front();
    queue1.pop();
    rep(i,sz(adj[current])){
      int to = adj[current][i];
      if (explored1[to] == -1){
        explored1[to] = explored1[current] + 1;
        queue1.push(to);
      }
    }
  }
  

  auto it1 = max_element(explored1.begin(), explored1.end());
  int u = distance(explored1.begin(), it1);

  // bfs
  vector<int> explored2(n + 1, -1);
  queue<int> queue2;
  explored2[u] = 0;
  queue2.push(u);
  while (!queue2.empty())
  {
    int current = queue2.front();
    queue2.pop();
    rep(i,sz(adj[current])){
      int to = adj[current][i];
      if (explored2[to] == -1){
        explored2[to] = explored2[current] + 1;
        queue2.push(to);
      }
    }
  }

  auto it2 = max_element(explored2.begin(), explored2.end());
  int max = *it2;
  cout << max + 1 << endl;
  return 0;
}
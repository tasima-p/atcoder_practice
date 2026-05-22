# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
# define rep(i,n) drep(i,0,n-1)
# define sz(s) (int)(s.size())
using namespace std;

int main() {
  int N,W;
  cin >> N >> W;
  vector<vector<long long>> WV(N+1);
  vector<vector<long long>> A(N+1, vector<long long>(W+1));

  WV[0] = {0,0};

  drep(i,1,N){
    int w,v;
    cin >> w >> v;
    WV[i] = {w,v};
  }

  sort(WV.begin(),WV.end(), [](const vector<long long> &alpha,const vector<long long> &beta){return alpha[0] < beta[0];});

  rep(i,N){
    A[i][0] = 0;
  }

  rep(i,W){
    A[0][i] = 0;
  }

  drep(n,1,N){
    drep(w,1,W){
      int d = w - WV[n][0];
      if (d < 0){
        continue;
      }
      A[n][w] = max(A[n-1][d] + WV[n][1], A[n][w-1]);
    }
  }

  rep(i,N+1){
    rep(j,W+1){
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }

  cout << A[N][W] << "\n";

}
# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
# define rep(i,n) drep(i,0,n-1)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i,N) cin >> H[i];
  vector<int> A(N);
  A[0] = 0;
  A[1] = abs(H[0] - H[1]);

  drep(i,2,N-1){
    if (A[i-2] + abs(H[i-2] - H[i]) > A[i-1] + abs(H[i-1] - H[i])){
      A[i] =  A[i-1] + abs(H[i-1] - H[i]);
    }else{
      A[i] =  A[i-2] + abs(H[i-2] - H[i]);
    }
  }


  cout << A[N-1] << "\n";

  return 0;
}
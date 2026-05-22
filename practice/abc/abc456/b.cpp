# include <bits/stdc++.h>
# define drep(i,cc,n) for(int i=(cc);i<(n);++i)
# define rep(i,n) drep(i,0,n)
# define sz(s) (int)(s.size())
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
using namespace std;

int main() {
  vector<int> A1(7);
  vector<int> A2(7);
  vector<int> A3(7);

  drep(i,1,7) cin >> A1[i];
  drep(i,1,7) cin >> A2[i];
  drep(i,1,7) cin >> A3[i];

  vector<int> cnt1(7,0);
  vector<int> cnt2(7,0);
  vector<int> cnt3(7,0);

  drep(i,1,7){
    drep(j,3,7){
      if(A1[i] == j){
        cnt1[j] += 1;
      }
      if(A2[i] == j){
        cnt2[j] += 1;
      }
      if(A3[i] == j){
        cnt3[j] += 1;
      }
    }
  }


  int cnt = 0;
  cnt += cnt1[4] * cnt2[5] * cnt3[6];
  cnt += cnt1[4] * cnt2[6] * cnt3[5];
  cnt += cnt1[5] * cnt2[6] * cnt3[4];
  cnt += cnt1[5] * cnt2[4] * cnt3[6];
  cnt += cnt1[6] * cnt2[5] * cnt3[4];
  cnt += cnt1[6] * cnt2[4] * cnt3[5];

  cout << (double) cnt / (6 * 6* 6);
  return 0;
}
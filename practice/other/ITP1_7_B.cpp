// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  while(true){
    int n,x,count;
    scanf("%lld %lld",&n,&x);
    if (n==0 && x == 0) break;
    count = 0;
    for(int i = 1; i <= n; i++){
      for(int j = i+1; j<=n; j++){
        for (int k = j+1; k <= n; k++){
          if(i + j + k == x){
            count++;
          }
        }
      }
    }
  }
}
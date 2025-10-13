#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n, eq_8, count = 0;
  cin >> n;
  for (int i = 1;i <= n; i+=2){
    eq_8 = 0;
    for (int j = 1; j <= i; j++){
      if(i%j == 0) eq_8++;
    }
    if (eq_8 == 8){
      count++;
    }
  }
  cout << count;
}
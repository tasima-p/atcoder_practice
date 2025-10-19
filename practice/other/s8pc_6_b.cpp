#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  vector<ll> list;
  ll n;
  vector<pair<ll,ll>> ab;

  cin >> n;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    ab.push_back({x, y});
  }

  sort(ab.begin(), ab.end());
  for (auto [x, y] : ab) {
    cout << x << " " << y << endl;
  }
}
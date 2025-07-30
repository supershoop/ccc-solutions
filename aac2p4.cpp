#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
ll T;
int main() {
  cin >> T;
  for (ll i = 0; i < T; i++) {
    ll N;
    cin >> N;
    vector v(N, 0ll);
    for (ll i = 0; i < N; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<>());

    if (N%2 == 0) {
      vector<ll> v2;
      for (ll i = 0; i < N/2;i++) {
        v2.push_back(v[i]);
        v2.push_back(v[i+N/2]);
      }
      v = move(v2);

    }
    ll sumA = 0, sumB = 0;
    for (ll i = 0; i < N; i++) {
      (i % 2 == 0 ? sumA : sumB) += v[i];
    }
    bool p = sumA > sumB;
    if (p) {
      for (ll i = 0; i < N; i++) {
        cout << v[i];
        cout << (i+1 < N ? ' ' : '\n');
      }
    } else {
      cout << "-1\n";
    }
  }
}
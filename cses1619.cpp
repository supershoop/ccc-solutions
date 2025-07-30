#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <string>

using ll = long long;
using namespace std;

map<ll, ll> change;
ll N;

int main() {
    cin >> N;
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        change[x]++, change[y]--;
    }
    ll c = 0, C = 0;
    for (const auto& [t, diff] : change) {
        c += diff;
        C = max(C, c);
    }
    cout << C;

}
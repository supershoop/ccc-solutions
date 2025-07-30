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

map<ll, ll> pos;
ll N, X;

int main() {
    cin >> N >> X;
    for (ll i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        if (pos.count(X - x)) {
            cout << i << ' ' << pos[X - x];
            return 0;
        }
        pos[x] = i;
    }
    cout << "IMPOSSIBLE";
}

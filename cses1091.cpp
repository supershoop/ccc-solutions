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

int main() {
    ll N, M;

    cin >> N >> M;
    multiset<ll> H;
    vector<ll> T(M, 0);
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        H.insert(x);
    }
    for (ll i = 0; i < M; i++) {
        ll x;
        cin >> x;
        auto iter = H.upper_bound(x);
        if (iter == H.begin()) {
            cout << "-1\n"; continue;
        }
        iter--;
        if (*iter > x) {
            cout << -1 << '\n'; continue;
        }
        cout << *iter << '\n';
        H.erase(iter);
    }

}
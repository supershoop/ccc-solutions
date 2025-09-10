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
#include <ext/pb_ds/assoc_container.hpp>

using ll = long long;
using namespace std;
using namespace __gnu_pbds;


ll N, K;
vector<pair<ll, ll>> movies;


int main() {
    cin >> N >> K;
    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        movies.emplace_back(b, a);
    }
    sort(movies.begin(), movies.end());
    multiset<ll> q;
    ll counter=0;
    for (ll i = 0; i < K; i++) q.insert(0);
    for (auto& [b, a] : movies) {
        auto iter = q.upper_bound(a);
        if (iter == q.begin()) continue;
        q.erase(--iter);
        q.insert(b);
        counter++;  // only when movie is actually assigned
    }

    cout << counter;
}
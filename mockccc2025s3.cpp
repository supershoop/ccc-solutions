#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>


using ll = long long;
using namespace std;

ll N, K;
set<ll> control;
vector<ll> ans;
map<ll, vector<ll>> regions;
unordered_map<ll, ll> s2i;
int main() {
    cin >> N >> K;
    for (ll i = 0; i < N; i++) {
        ll l, r, s;
        cin >> l >> r >> s;
        l--;
        regions[l].emplace_back(s);
        regions[r].emplace_back(s);
        s2i[s] = i;
    }

    ans.resize(N);
    set<ll, std::greater<>> sorcerers;
    ll prev = 0;
    for (auto& [pos, events] : regions) {
        if (!sorcerers.empty()) {
            ans[s2i[*sorcerers.begin()]] += pos-prev;
        }
        for (ll event : events) {
            if (sorcerers.count(event)) sorcerers.erase(event);
            else sorcerers.insert(event);
        }
        prev = pos;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
}
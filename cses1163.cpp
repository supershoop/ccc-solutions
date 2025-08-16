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

set<ll> interrupts;
priority_queue<tuple<ll, ll, ll>> blocks; // length, start, end
ll X, N;

int main() {
    cin >> X >> N;
    blocks.emplace(X, 0, X);
    for (ll i = 0; i < N; i++) {

        ll light;
        cin >> light;
        interrupts.insert(light);
        auto iter = interrupts.upper_bound(get<1>(blocks.top()));
        while (iter != interrupts.end() && *iter <= get<2>(blocks.top())) {
            auto [_, l, r] = blocks.top(); blocks.pop();
            auto m = *iter;
            blocks.emplace(m-l, l, m);
            blocks.emplace(r-m, m, r);
            interrupts.erase(iter);
            iter = interrupts.lower_bound(get<1>(blocks.top()));
        }
        cout << get<0>(blocks.top()) << ' ';
    }

}
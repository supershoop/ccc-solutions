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

ll N;

int main() {
    cin >> N;
    vector<pair<ll, ll>> stack;
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        while (!stack.empty() && stack.back().first >= x) stack.pop_back();
        ll ans=0;
        if (!stack.empty()) {
            ans = stack.back().second;
        }
        cout << ans << ' ';
        stack.emplace_back(x, i+1);
    }

}
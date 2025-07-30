#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

vector<ll> dp;
unordered_map<ll, ll> dp_map;
ll W;

ll calc(ll w) {
    if (w <= 2) return 1;
    if (w < dp.size() && dp[w]!= -1) return dp[w];
    if (w >= dp.size() && dp_map.count(w)) return dp[w];
    ll c = 0;
    for (ll children = 2; children <= w; children++) {
        c += calc(w / children);
    }
    if (w < dp.size()) dp[w] = c;
    else dp_map[w] = c;
    return c;
}

int main() {
    dp.resize(256e6 / sizeof(ll), -1);
    cin >> W;
    cout << calc(W);
}
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
char _;

using ll = long long;
using namespace std;

ll N, X;

map<ll, ll> s;
vector<ll> A;
vector<tuple<ll, ll, ll>> pairs;
map<ll, vector<pair<ll, ll>>> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    A.resize(N);
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        A[i]=x;
        s[x]=i;
    }
    for (ll i = 0; i < N; i++) {
        for (ll j = i+1; j < N; j++) {
            pairs.emplace_back(A[i]+A[j], i, j);
            mp[A[i]+A[j]].emplace_back(i, j);
        }
    }
    for (ll i = 0; i < pairs.size(); i++) {
        const auto& [a, x, y] = pairs[i];
        if (!mp.count(X-a)) continue;
        for (const auto& [w, z] : mp[X-a]) {
            if (x != w && y!=w && y!=z && x != z) {
                printf("%d %d %d %d", x+1, y+1, w+1, z+1);
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";

}
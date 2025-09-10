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

using iset = tree<ll, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update>;

ll N, X;

int main() {
    cin >> N >> X;
    vector<ll> v(N+1, 0);
    for (ll i = 0; i < N; i++) {
        cin >> v[i];
    }
    map<ll, ll> seen;
    iset s;
    ll total=0;
    for (ll i = 1; i <= N; i++) {
        ll x = v[i-1];
        if (seen.count(x)) {
            s.erase(seen[x]);
        }
        seen[x]=i;
        s.insert(i);
        ll j = s.find_by_order(X) == s.end() ? 0 : *s.find_by_order(X);
        total += (i-j);
    }
    cout << total;

}
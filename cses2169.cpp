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

vector<tuple<ll, ll, ll>> ranges;
map<ll, ll> m;
map<ll, ll> m2;
ll N;

using mset = tree<ll, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    cin >> N;
    for (ll i = 0; i<N;i++) {
        ll x, y;
        cin >> x >> y;
        ranges.emplace_back(x, -y, i);
    }
    sort(ranges.begin(), ranges.end());

    vector<ll> contains(N, false);
    vector<ll> contained(N, false);
    mset r;
    for (ll n = N-1; n >=0; n--) {
        const auto& [x, y, i] = ranges[n];
        contains[i]=r.order_of_key(-y+1);
        r.insert(-y);
    }
    r.clear();
    for (const auto& [x, y, i] : ranges) {
        contained[i]=r.order_of_key(y+1);
        r.insert(y);
    }

    for (ll x : contains) {
        cout << x << ' ';
    }
    cout << '\n';
    for (ll x : contained) {
        cout << x << ' ';
    }

}
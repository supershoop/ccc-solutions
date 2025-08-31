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

vector<tuple<ll, ll, ll>> ranges;
map<ll, ll> m;
map<ll, ll> m2;
ll N;
int main() {
    cin >> N;
    for (ll i = 0; i<N;i++) {
        ll x, y;
        cin >> x >> y;
        ranges.emplace_back(x, y, i);
        m[x]=max(m[x], y);
        if (!m2.count(x)) m2[x]=y;
        else m2[x]=min(m2[x], y);
    }
    sort(ranges.begin(), ranges.end());

    vector<bool> contains(N, false);
    vector<bool> contained(N, false);
    ll minR=LLONG_MAX;
    for (ll n = N-1; n >=0; n--) {
        const auto& [x, y, i] = ranges[n];
        if (y>=minR || y>m2[x]) {
            contains[i]=true;
        }
        minR=min(minR, y);
    }
    ll maxR=0;
    for (const auto& [x, y, i] : ranges) {
        if (y<=maxR || m[x]>y) contained[i]=true;
        maxR=max(maxR, y);
    }

    for (bool x : contains) {
        cout << x << ' ';
    }
    cout << '\n';
    for (bool x : contained) {
        cout << x << ' ';
    }

}
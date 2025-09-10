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


ll N, a, b;
vector<ll> prefix;

int main() {
    cin >> N >> a >> b;
    prefix.resize(N+1, 0);
    multiset<ll> s;
    ll best = -LLONG_MAX;
    for (ll i = 1; i <= N; i++) {
        cin >> prefix[i];
        prefix[i]+=prefix[i-1];
        if (i > b) {
            s.erase(s.find(prefix[i-b-1]));
        }
        if (i >= a) {
            s.insert(prefix[i-a]);
            best = max(best, prefix[i]-*s.begin());
        }
    }
    cout << best;
}
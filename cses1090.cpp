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

ll N, X;

int main() {
    cin >> N >> X;
    multiset<ll, greater<>> P;
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        P.insert(x);
    }

    ll C=0;
    while (!P.empty()) {
        auto low = P.begin();
        ll n = *low;
        P.erase(low);
        auto high = P.lower_bound(X-n);
        C++;
        if (high != P.end()) P.erase(high);
    }
    cout << C;

}
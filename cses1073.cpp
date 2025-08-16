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
    multiset<ll> tops;
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        auto iter = tops.upper_bound(x);
        if (iter == tops.end()) {
            tops.insert(x);
        } else {
            tops.erase(iter);
            tops.insert(x);
        }
    }

    cout << tops.size();

}
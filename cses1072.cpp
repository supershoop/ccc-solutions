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

ll n;
int main() {
    cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll ans = (k * k) * (k * k - 1) / 2;
        ans -= (max(0ll, k - 2) * (k-1) * 4);
        cout << ans << '\n';
    }

}
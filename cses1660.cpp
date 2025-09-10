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
    vector<ll> v(N+1, 0);
    for (ll i = 1; i <= N; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    ll i = 0, j = 1;
    ll ans=0;
    while (j <= N) {
        auto val = v[j]-v[i];
        if (val == X) {
            ans++;
            i++;
            j++;
        }
        else if (v[i] > v[i+1]) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans;

}
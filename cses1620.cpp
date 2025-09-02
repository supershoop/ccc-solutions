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

using ll = unsigned long long;
using namespace std;

constexpr ll MAXIMUM_T = 2e5 * 10e9;
ll N, T;
vector<ll> machines;

ll calc(ll time) {
    ll total=0;
    for (auto machine : machines) {
        total += (ll) (time/machine);
    }
    return total;
}

int main() {
    cin >> N >> T;
    machines.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> machines[i];
    }
    ll x = 0;
    for (ll b = MAXIMUM_T; b >= 1; b/=2) {
        while (calc(x+b) < T) x+=b;
    }
    cout << x+1;

}
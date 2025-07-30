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

constexpr ll MAXIMUM = 10e9;

ll N;
vector<ll> P;

ll cost(ll target) {
    ll C = 0;
    for (auto v : P) {
        C += abs(v-target);
    }
    return C;
}

int main() {
    cin >> N;
    P.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> P[i];
    }

    ll x = -1;
    for (ll b = MAXIMUM/2; b >= 1; b/=2) {
        while (cost(x+b)>cost(x+b+1)) x += b;
    }
    cout << cost(x+1);
}
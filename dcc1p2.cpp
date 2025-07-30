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

ll T;
int main() {
    cin >> T;
    vector<ll> squares;
    vector<tuple<ll, ll, ll>> inputs;
    vector<ll> outputs;
    ll maxSum = 0;
    for (ll i = 0; i < T; i++) {
        ll a, b;
        cin >> a >> b;
        inputs.emplace_back(a+b, min(a, b), max(a, b));
        maxSum = max(maxSum, a+b);
    }
    outputs.resize(inputs.size(), 1);
    sort(inputs.begin(), inputs.end());
    for (ll i = 1;; i++) {
        if (i*i > maxSum) break;
        ll square = i*i;
        for (ll n = inputs.size() - 1; n >= 0; n--) {
            auto& [sum, a, b] = inputs[n];
                if (square > a+b) break;
                if (square < min(a, b)) {
                    outputs[n] += square + 1;
                } else {
                    outputs[n] += a + 1;
                    if (b<square) {
                        outputs[n] -= (square-b);
                    }
                }
                outputs[n] %= 998244353;
            }
    }
    for (const auto o : outputs) {
        cout << o << '\n';
    }
}
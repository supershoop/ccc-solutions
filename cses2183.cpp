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

vector<ll> coins;
ll N;
int main() {
    cin >> N;
    coins.resize(N);
    for (ll i = 0; i<N; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    ll limit = 1;
    for (ll x : coins) {
        if (x > limit) break;
        limit += x;
    }
    cout << limit;
}
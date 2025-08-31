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

map<ll, ll> n;

constexpr ll mod =1e9+7;
ll N;
int main() {
    cin >> N;
    ll total = 1;
    for (ll i =0 ; i < N; i++) {
        ll x;
        cin >> x;
        n[x]++;
    }
    for (const auto& [num, freq] : n) {
        total *= (freq+1);
        total%=mod;
    }
    total = (total+mod-1)%mod;
    cout << total;
}
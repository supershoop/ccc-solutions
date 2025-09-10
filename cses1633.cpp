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
vector<ll> dp(1e6+1, -1);
constexpr ll mod = 1e9+7;
ll calc(ll n) {
    if (n<0) return 0;
    if (n==0) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = calc(n-1)+calc(n-2)+calc(n-3)+calc(n-4)+calc(n-5)+calc(n-6);
    dp[n]%=mod;
    return dp[n];
}

int main() {
    ll n;
    cin >> n;
    cout << calc(n);
}
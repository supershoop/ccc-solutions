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

map<ll, ll> location;
vector<ll> arr;
vector<ll> cache;

ll recur(ll pos) {
    if (pos < 0) return 0;
    if (cache[pos]!=-1) return cache[pos];
    ll x = recur(pos-1) + 1;
    if (location.count(arr[pos])) {
        x -= recur(location[arr[pos]]);
    }
    cache[pos]=x;
    return x;
}

ll N;
int main() {
    cin >> N;
    arr.resize(N);
    cache.resize(N, -1);
    ll C = 0;
    ll left=0;
    for (ll i =0 ; i < N; i++) {
        ll x;
        cin >> x;
        left = max(left, location[x]);
        C += (i+1)- left;
        location[x] = i+1;
    }
    cout << C;

}
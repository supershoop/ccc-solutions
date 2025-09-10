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
map<ll, ll> mp;
int main() {
    cin >> N;
    ll sum=0;
    ll count=0;
    for (ll i = 1; i <= N; i++) {
        mp[sum]++;
        ll x;
        cin >> x;
        sum += x;
        sum %= N;
        if (mp.count(sum)) count+= mp[sum];
        if (mp.count(sum-N)) count+= mp[sum-N];
        if (mp.count(sum+N)) count+= mp[sum+N];
    }
    cout << count;

}
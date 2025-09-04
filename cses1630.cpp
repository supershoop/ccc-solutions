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

int main() {
    cin >> N;
    ll sum = 0;
    vector<ll> times;
    for (ll i = 0; i < N; i++) {
        ll a, d;
        cin >> a >> d;
        sum+=d;
        times.push_back(a);
    }
    sort(times.begin(), times.end());
    ll accum=0;
    for (auto time : times) {
        accum+=time;
        sum-=accum;
    }
    cout << sum;

}
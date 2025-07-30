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

    set<ll> s;

int main() {
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();

}
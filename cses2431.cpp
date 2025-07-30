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
#include <cmath>

using ll = long long;
using namespace std;

char solve(ll x) {
    ll exp = 0; //  exp
    ll digits = 0; // digits
    ll power = 1;

    while (digits + 9*power*(exp+1) < x) {
        exp++;
        digits += 9*power*exp;
        power*=10;
    }
    ll pos = x-digits-1;
    ll num = power+(pos/(exp+1));
    ll idx = pos%(exp+1);
    return to_string(num)[idx];
}

int main() {
    ll T;
    cin >> T;
    for (ll i = 0; i < T; i++) {
        ll X;
        cin >> X;
        cout << solve(X) << '\n';
    }


}
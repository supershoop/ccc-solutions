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


ll diff = LLONG_MAX;

void solve(vector<ll> remaining, ll left = 0, ll right = 0) {
    if (remaining.size() == 0) {
        diff = min(diff, abs(left-right));
        return;
    }
    ll next = remaining.back();
    remaining.pop_back();
    solve(remaining, left+next, right);
    solve(remaining, left, right+next);
}
ll N;
int main() {
    cin >> N;
    vector<ll> n;
    for (int i= 0; i < N; i++) {
        ll x;
        cin >> x;
        n.push_back(x);
    }
    solve(n);
    cout << diff;
}
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


ll n;
int main() {
    cin >> n;
    ll c = 1;
    for (ll i = 0; i < n; i++) {
        c *= 2;
        c %= 1000000007;
    }
    cout << c;

}
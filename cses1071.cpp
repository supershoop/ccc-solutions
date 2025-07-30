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
ll T;
int main() {
    cin >> T;
    for (ll i = 0; i < T; i++) {
        ll x, y;
        cin >> y >> x;
        bool flip = y > x;
        ll x2 = x;
        x = max(x, y);
        y = min(x2, y);
        ll bottom = x * (x - 1) + 1;
        y = x - y;
        cout << (flip != x % 2 == 1 ? bottom+y : bottom-y) << '\n';


    }

}
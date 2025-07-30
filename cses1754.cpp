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
        ll a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        while (a > b) {
            a -= 2;
            b--;
        }
        cout << (a == b && a%3==0 && a >= 0 ? "YES" : "NO");
        cout << '\n';
    }

}
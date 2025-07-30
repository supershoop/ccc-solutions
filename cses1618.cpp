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
    ll fives = 0;
    ll twos = 0;
    for (ll power = 2; power <= n; power *= 2) {
        twos += (n / power);
    }
    for (ll power = 5; power <= n; power *= 5) {
        fives += (n / power);
    }
    cout << min(fives, twos);
}
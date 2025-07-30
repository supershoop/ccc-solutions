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
    vector<unordered_set<ll>> col(n);
    vector<unordered_set<ll>> row(n);
    vector<vector<ll>> out(n, vector(n, 0ll));
    for (ll y = 0; y < n; y++) {
         for (ll x = 0; x < n; x++) {
            ll n = 0;
            while (row[y].count(n) || col[x].count(n)) n++;
            out[y][x] = n;
            row[y].insert(n);
            col[x].insert(n);
        }
    }
    for (auto& y : out) {
        for (auto& x : y) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
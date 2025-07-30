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

    vector<pair<ll, ll>> movies;
    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        movies.emplace_back(b,a);
    }
    sort(movies.begin(), movies.end());

    ll lastEnd=0, C=0;
    for (const auto& [end, beg] : movies) {
        if (beg >= lastEnd) {
            C++;
            lastEnd = end;
        }
    }
    cout << C;

}
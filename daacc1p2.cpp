#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;

using ll = long long;
ll water = 0;
ll fire = 1;
ll grass = 2;

double damage[3][3] = {
    {1, 2, 0.5},
    {0.5, 1, 2},
    {2, 0.5, 1}
};

ll type(string s) {
    if (s == "FIRE") return fire;
    if (s == "WATER") return water;
    if (s == "GRASS") return grass;
}

int main() {
    ll dmg = 0;
    string t;
    ll N;
    cin >> t >> N;
    ll E = type(t);
    for (ll i = 0; i < N; i++) {
        ll d;
        cin >> d >> t;
        ll T = type(t);
        dmg = max(dmg, (ll) floor(d * damage[T][E]));
    }
    cout << dmg;

}
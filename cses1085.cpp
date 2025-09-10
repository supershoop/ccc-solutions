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
#include <ext/pb_ds/assoc_container.hpp>

using ll = long long;
using namespace std;
using namespace __gnu_pbds;

using iset = tree<ll, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update>;

ll N, K;

vector<ll> X;
bool good(ll target) {
    ll counter=0;
    ll arrays = 1;
    for (ll i = 0; i < N; i++) {
        if (X[i] > target) return false;
        if (counter + X[i] > target) {
            counter = 0;
            arrays++;
            if (arrays > K) return false;
        }
        counter += X[i];
    }
    return true;
}


int main() {
    cin >> N >> K;
    X.resize(N, 0);
    ll maxVal=0;
    for (ll i = 0; i < N; i++) {
        cin >> X[i];
        maxVal = max(maxVal, X[i]);
    }
    ll x = 0;
    for (ll b = maxVal * ceil(N/K); b >= 1; b/= 2) {
        while (!good(x+b)) x += b;
    }
    cout << x + 1;
}
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <iostream>
#include <cmath>

using ll = long long;
using namespace std;

ll X, Y ,Z, N;
int main() {
    cin >> X >> Y >> Z >> N;

    double T = INFINITY;
    for (ll i = 0; i < N; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        double diff = sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
        if (Z == z) {
            T = min(T, diff/2);
        } else if (z < Z) {
            T = min(T, diff/2 + (Z-z));
        } else {
            double timeGliding = (z-Z) / 4.;
            diff = max(0., diff - 3 * timeGliding);
            T = min(T, diff/2 + timeGliding);

        }
    }
    cout << T;
}
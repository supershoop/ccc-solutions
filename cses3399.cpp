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
        ll N, a, b;
        cin >> N >> a >> b;
        unordered_set<ll> cardsA;
        unordered_set<ll> cardsB;
        vector<ll> A;
        vector<ll> B;


        ll n = a+b;
        bool flag = a+b;
        ll pa, pb;


        for (ll j = 0; j < n; j++) {
            B.push_back((j + a) % n + 1);
        }
        for (ll j = n + 1; j <= N; j++) {
            B.push_back(j);
        }

        ll x = 0, y = 0;
        for (ll j = 0; j < N; j++) {
            if (j+1>B[j]) x++;
            if (j+1<B[j]) y++;
        }

        if (x!=a || y!=b) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (ll x = 1; x <= N; x++) {
                cout << x << ' ';
            }
            cout << '\n';
            for (ll x : B) {
                cout << x  << ' ';
            }
            cout << '\n';
        }
    }

}
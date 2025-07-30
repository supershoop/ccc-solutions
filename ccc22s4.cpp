#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;
using ll = long long;
ll N, C;
vector<ll> PS;
vector<ll> P;

int main() {
    cin >> N >> C;
    P.resize(C, 0);
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        P[x]++;
    }
    PS.resize(C, 0);
    ll sum = 0;
    for (ll i = 0; i < C; i++) {
        sum += P[i];
        PS[i] = sum;

    }
    ll count = (N)*(N-1)*(N-2)/6;
    ll half = C / 2;
    for (int i = 0; i < C; i++) {
        ll opp = (i + half) % C;
        ll between;
        if (i < opp) {
            between = PS[opp] - PS[i];
        } else {
            between = PS[opp] + PS[C-1] - PS[i];
        }

        count -= P[i] * (P[i] - 1) * (P[i] - 2) / 6;
        count -= P[i] * between * (between - 1 ) / 2;
        count -= P[i] * (P[i] - 1) * between / 2;
    }

    if (C % 2 == 0) {
        for (ll i = 0; i < half; i++) {
            ll opp = i + half;
            count += P[i] * P[opp] * (P[opp] -1) / 2;
            count += P[i] * P[opp] * (P[i] -1) / 2;
        }
    }
    cout << count;
}
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

ll M, N, K;

int main() {
    cin >> N >> M >> K;

    vector<ll> A;
    vector<ll> B;
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        A.push_back(x);
    }
    for (ll i = 0; i < M; i++) {
        ll x;
        cin >> x;
        B.push_back(x);
    }

    ll x=0, y=0, C=0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    while (x<N) {
        while (y<M && A[x]-B[y] > K) y++;
        if (A[x]-B[y] < -K) {
            x++; continue;
        }
        if (y==M)break;
        C++;
        x++;
        y++;
    }
    cout << C;

}
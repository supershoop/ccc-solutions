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

vector<ll> mapping;
ll N;
int main() {
    cin >> N;
    mapping.resize(N);
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        mapping[x-1]=i;
    }
    ll nextN=0;
    ll C = 0;
    while (nextN<N) {
        C++;
        ll pos = 0;
        while (nextN < N && mapping[nextN] >= pos) {
            pos=mapping[nextN];
            nextN++;
        }
    }
    cout << C;

}
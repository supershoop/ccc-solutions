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
    ll largest=0;
    ll S=0;
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        S+=x;
        largest=max(largest, x);
    }

    cout << (largest*2 > S ? largest*2 : S);
}
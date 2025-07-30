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
#include <bitset>

using ll = long long;
using namespace std;



ll N;
int main() {
    cin >> N;
    vector<ll> out;
    out.reserve(1 << N);
for (ll i = 0; i < 1 << N; i++) {
        out.push_back(i ^ (i>>1));
    }

    for (auto n : out) {
        for (ll i = N-1; i >=0; i--) {
            cout << (n >> i & 1);
        }
        cout << '\n';
    }


}
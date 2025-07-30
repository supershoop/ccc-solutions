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

vector<ll> nums;
ll N;
int main() {
    cin >> N;
    ll half = N/2;
    if (N == 1) { cout << 1; exit(0); }
    if (N <= 3) {
        cout << "NO SOLUTION"; exit(0);
    }
    for (ll i = 2; i <= N; i+=2) {
        cout << i << ' ';
    }
    for (ll i = 1; i <= N; i+=2) {
        cout << i << ' ';
    }
}
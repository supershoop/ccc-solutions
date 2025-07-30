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
    ll sum = N * (N + 1) / 2;
    if (sum % 2 == 1) cout << "NO";
    else {
        ll half = sum/2;
        vector<ll> set1;
        vector<ll> set2;
        ll count = 0;
        for (ll i = N; i >= 1; i--) {
            if (count+i <= half) {
                count += i;
                set1.push_back(i);
            } else {
                set2.push_back(i);
            }
        }
        cout << "YES" << '\n';
        cout << set1.size() << '\n';
        for (auto i : set1) cout << i << ' ';
        cout << '\n' << set2.size() << '\n';
        for (auto i : set2) cout << i << ' ';
    }

}
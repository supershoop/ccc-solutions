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

int main() {
    vector<ll> nums;
    ll n;
    cin >> n;
    nums.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll sum = 0;
    for (ll i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            ll diff = nums[i-1] - nums[i];
            sum += diff;
            nums[i] = nums[i-1];
        }
    }
    cout << sum;

}
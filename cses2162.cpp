#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <list>
#include <string>

using ll = long long;
using namespace std;

ll N;
vector<ll> nums;
int main() {
    cin >> N;
    for (ll i = 0; i<N;i++) {
        nums.push_back(i);
    }
    for (ll i = 0; i < nums.size(); i++) {
        if (i%2==1) {
            cout << nums[i]+1 << ' ';
        } else nums.push_back(nums[i]);
    }


}
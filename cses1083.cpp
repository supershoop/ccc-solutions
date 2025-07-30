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
ll n;
int main() {
    cin >> n;
    vector<bool> c(n, false);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        c[x-1] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!c[i]) cout << i+1;
    }

}
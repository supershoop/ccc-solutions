#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == m || m == n + 1) cout << "stressed";
    else if (m < n) cout << "relaxed";
    else cout << "okay";
}
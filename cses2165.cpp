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

void hanoi(ll disk, ll source, ll dest, ll spare) {
    if (disk == 1) {
        cout << source << ' ' << dest << '\n';
    } else {
        hanoi(disk-1, source, spare, dest);
        cout << source << ' ' << dest << '\n';
        hanoi(disk-1, spare, dest, source);
    }
}

int main() {
    cin >> n;
    cout << ((1 << n) - 1) << '\n';
    hanoi(n, 1, 3, 2);


}
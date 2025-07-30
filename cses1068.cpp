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
    while (n != 1) {
        cout << n << ' ';
        if (n%2==0) n/=2;
        else n = n * 3 + 1;
    }
    cout << n;

}
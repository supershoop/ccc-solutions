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

string s;

int main() {
    cin >> s;

    ll i = 0;
    ll longest = 0;
    while (i < s.size()) {
        ll j = i+1;
        while (s[j]==s[i]) j++;
        longest = max(longest, j - i);
        i = j;
    }
    cout << longest;
}
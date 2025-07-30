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
#include <list>

using ll = long long;
using namespace std;

string S;
multiset<char> M;

array<ll, 26> chars;

bool good() {
    ll mode = 0;
    ll total = 0;
    for (ll count : chars) {
        total += count;
        mode = max(mode, count);
    }
    return mode*2<=total+1;
}

bool solve(string& ref, char prev=0, ll n=1) {
    for (char x = 'A'; x <= 'Z'; x++) {
        ll& y = chars[x-'A'];
        if (x==prev || y==0) continue;
        y--;
        if (good()) {
            ref[n-1]=x;
            if (n==S.size() || solve(ref, x, n+1)) return true;
        }
        y++;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);
    cin >> S;
    for (char c : S) chars[c-'A']++;
    string ref(S.size(), 0);
    bool flag = solve(ref);
    cout << (flag ? ref : "-1");
}
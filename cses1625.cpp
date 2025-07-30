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

string S;

array<array<bool, 7>, 7> visited;

ll C = 0;

bool good(ll y, ll x) {
    return min(y, x) >= 0 && max(y, x) < 7 && !visited[y][x];
}

void dfs(ll y, ll x, ll n=0) {
    if (!good(y,x)) return;

    if (!good(y-1,x) && !good(y+1, x) && good(y, x-1) && good(y, x+1)) return;
    if (!good(y,x-1) && !good(y, x+1) && good(y-1, x) && good(y+1, x)) return;
    if (!good(y, x-1) && !good(y+1, x) && good (y+1, x-1)) return;
    if (!good(y, x-1) && !good(y-1, x) && good (y-1, x-1)) return;
    if (!good(y, x+1) && !good(y+1, x) && good (y+1, x+1)) return;
    if (!good(y, x+1) && !good(y-1, x) && good (y-1, x+1)) return;

    if (y==6&&x==0) {
        if (n==48) C++;
        return;
    }
    visited[y][x] = true;
    ll s = S[n];
    if (s=='?'||s=='U') dfs(y-1,x,n+1);
    if (s=='?'||s=='D') dfs(y+1,x,n+1);
    if (s=='?'||s=='L') dfs(y,x-1,n+1);
    if (s=='?'||s=='R') dfs(y,x+1,n+1);
    visited[y][x] = false;
}

int main() {
    cin >> S;
    dfs(0, 0);
    cout << C;
}
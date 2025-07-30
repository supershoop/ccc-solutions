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


ll N, M;

int main() {
    cin >> N >> M;

    vector<string> grid(N);
    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < M; j++) {
            char n = s[j];
            while ((i!=0 && grid[i-1][j]==n) || (j!=0 && grid[i][j-1]==n) || (n==s[j])) {
                n++;
                if (n=='E') n='A';
            }
            grid[i].push_back(n);
        }
    }

    bool flag = false;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            char x = grid[i][j];
            if (i!=0 && grid[i-1][j]==x) flag = true;
            if (i!=N-1 && grid[i+1][j]==x) flag = true;
            if (j!=0 && grid[i][j-1]==x) flag = true;
            if (j!=M-1 && grid[i][j+1]==x) flag = true;
        }
    }

    if (flag) {
        cout << "IMPOSSIBLE";
    } else for (auto& s : grid) {
        cout << s << '\n';
    }

}
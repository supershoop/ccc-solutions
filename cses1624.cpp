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
#include <bitset>
#include <array>

using ll = long long;
using namespace std;


array<bool, 8> row;
array<bool, 8> col;
array<bool, 15> diag1;
array<bool, 15> diag2;
vector<vector<bool>> reserved(8, vector(8, false));

int _d1(int x, int y) {
  return 7 + (y-x);
}

int _d2(int x, int y) {
    x=7-x;
  return 7 + (y-x);
}

int C = 0;

void solve(int y=0, int n = 0) {
        for (int x = 0; x < 8; x++) {
            if (reserved[y][x] || col[x] || diag1[_d1(x, y)] || diag2[_d2(x, y)]) continue;
            if (n==7) {
                C++;
                continue;
            }
            col[x] = true;
            diag1[_d1(x, y)] = true;
            diag2[_d2(x, y)] = true;
            solve(y+1, n + 1);
            col[x] = false;
            diag1[_d1(x, y)] = false;
            diag2[_d2(x, y)] = false;
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '*') reserved[i][j] = true;
          //  cout << _d1(i, j) << '\t';
        }
        //cout << '\n';
    }
    solve();
    cout << C;

}
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<vector<int>> dp;
vector<int> l, r;
int W, L, R;



int main() {
    cin >> W >> L >> R;
    l.resize(L), r.resize(R);
    for (int i = 0; i < L; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < R; i++) {
        cin >> r[i];
    }
    dp.resize(1 << (L-1), vector(1 << (R-1), INT_MAX));
    dp[1 << (L - 1) - 1][1 << (R-1) -1] = 0;


}
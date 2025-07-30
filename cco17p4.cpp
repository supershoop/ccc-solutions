#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

constexpr ll MAX = 25005;

int N;
int main() {
    cin >> N;
    // [pillar][volume]=heights
    vector<ll> dp[2] { vector(MAX, 0ll), vector(MAX, 0ll) };
    vector<ll> pillars(N);
    for (int i = 0; i < N; i++) {
        cin >> pillars[i];
    }
    sort(pillars.begin(), pillars.end(), greater<>());
    pillars[0] = 51;
    dp[0][0] = 1ll << pillars[0];
    for (int i = 1; i < N; i++) {
        int prev = (~i) & 1;
        int cur = i & 1;
        for (int j = 0; j < MAX; j++) {
            if (dp[prev][j] != 0) {
                dp[cur][j] |= dp[prev][j] | 1ll << pillars[i];
                for (int level = 0; level <= 50; level++) {
                    if (dp[prev][j] >> level & 1 && level > pillars[i]) {
                        size_t volume = j + level - pillars[i];
                        if (volume < MAX) {
                            dp[cur][volume] |= dp[cur][j];
                        }
                    }
                }
            }
        }
        fill(begin(dp[prev]), end(dp[prev]), 0);
    }
    for (int i = 0; i < MAX; i++) {
        if (dp[N&1^1][i] != 0) cout << i << ' ';
    }
}
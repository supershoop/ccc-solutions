#include <vector>
#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
vector<ll> T[2];
vector<ld> P[2];
vector<ll> dp[2];

int main() {
    cin >> N;
    T[0].resize(N+1);
    T[1].resize(N+1);
    P[0].resize(N+1);
    P[1].resize(N+1);
    dp[0].resize(N+1);
    dp[1].resize(N+1);
    ld avg = 0;
    for (ll i = 1; i <= N; i++) {
        cin >> T[0][i];
        avg += T[0][i];
    }
    for (ll i = 1; i <= N; i++) {
        cin >> T[1][i];
        avg += T[1][i];
    }
    avg /= N * 2;
    for (ll j = 0; j < 2; j++) {
        ll sum = 0;
        for (ll i = 1; i <= N; i++) {
            sum += T[j][i] - avg;
            P[j][i] = sum;
        }
    }
    dp[0][0]=0;
    dp[1][0]=0;
    for (int i = 1; i <= N; i++) {
        for (int r = 0; r < 2; r++) {
            ll v = dp[r][i-1];
            v = max(v, dp[1-r][i-1]);
            for (int j = i-1; j>=0;j--) {
                if (P[1-r][j]==P[1-r][i]) {
                    v = max(v, dp[r][j]+1);
                    break;
                }
            }
            for (int j = i-1; j>=0;j--) {
                if (P[r][i]==-P[1-r][j]) {
                    v = max(v, dp[1-r][j]+1);
                    break;
                }
            }
        dp[r][i] = v;
        }
            if (P[0][i] == -P[1][i]) {
                dp[0][i] = (dp[1][i] = max(dp[0][i], dp[1][i]) + 1);
            }
    }
    cout << dp[0][N];
}
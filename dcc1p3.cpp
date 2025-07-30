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

vector<vector<ll>> S;
vector<vector<ll>> P;

ll M, N;
int main() {
    cin >> N >> M;

    P.resize(N+1, vector(M+1, 0ll));
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            cin >> P[i][j];
        }
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            P[i][j] += P[i-1][j];
            P[i][j] += P[i][j-1];
            P[i][j] -= P[i-1][j-1];
        }
    }
    ll A = 0;
    for (ll H = N; H > 0; H--) {
        for (ll y = 0; y+H<=N; y++) {
            {
                ll i = 0, j = M;
                while (i < j) {
                    ll W = (j-i);
                    ll side1 = P[y+H][i+W/2] - P[y+H][i] - P[y][i+W/2] + P[y][i];
                    ll side2 = P[y+H][i+W] - P[y+H][i+W/2] - P[y][i+W] + P[y][i+W/2];
                    if (side1 == side2) {
                        A=max(A, W*H);
                        break;
                    } else if (side1 < side2) {
                        j -= W % 2 == 0 ? 2 : 1;
                    } else {
                        i += W % 2 == 0 ? 2 : 1;
                    }
                }
            }
        }
    }
    cout << A;
}
#include <queue>
#include <vector>
#include <iostream>
#include <tuple>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
using ll = long long;

int N, M;

vector<ll> V;
vector<vector<pair<ll, ll>>> adj;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scan(N);
    scan(M);
    V.resize(N);
    for (int i = 0; i < N; i++) {
        scan(V[i]);
    }

    adj.resize(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        scan(a);
        scan(b);
        scan(c);
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    vector best(N, 0ll);
    for (int i = 0; i < N; i++) {
        best[i] = V[i];
    }
    for (int i = 0; i < N; i++) {
        queue<pair<ll, ll>> q;
        q.emplace(V[i], i);
        while (!q.empty()) {
            auto [profit, x] = q.front(); q.pop();
            for (auto& [to, c] : adj[x]) {
                if (profit-c > best[to]) {
                    best[to]=profit-c;
                    q.emplace(profit-c, to);
                }
            }
        }
    }
    for (auto v : best) {
        cout << v << '\n';
    }
}
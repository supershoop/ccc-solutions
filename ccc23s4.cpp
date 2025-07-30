#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
using namespace std;
using ll = long long;
using edge = tuple<ll, ll, ll, ll>; // l, c, u, v

ll N, M;
vector<ll> link;
vector<ll> sizes;
vector<vector<pair<ll, ll>>> adj; // dest, l
vector<ll> dist;

ll find(ll x) {
    while (link[x] != x) x = link[x];
    return x;
}

void unite(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a, b);
    // a > b
    link[b] = a;
    sizes[a] += sizes[b];
}

void dijk(ll a) {
    priority_queue<pair<ll, ll>> q;
    q.emplace(0, a);
    fill(dist.begin(), dist.end(), LONG_LONG_MAX);
    dist[a] = 0;
    while (!q.empty()) {
        auto [_, x] = q.top(); q.pop();
        for (auto& [dest, l] : adj[x]) {
            if (dist[x]+l < dist[dest]) {
                dist[dest] = dist[x]+l;
                q.emplace(-dist[dest], dest);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    vector<edge> edges;
    adj.resize(N);
    for (ll i = 0; i < M; i++) {
        ll u, v, l, c;
        cin >> u >> v >> l >> c;
        u--;
        v--;
        edges.emplace_back(l, c, u, v);
    }

    link.resize(N);
    sizes.resize(N, 1);
    for (ll i = 0; i < N; i++) {
        link[i] = i;
    }

    ll cost = 0;
    sort(edges.begin(), edges.end());
    dist.resize(N);
    for (auto& [l, c, u, v] : edges) {
        dijk(u);
        if (l < dist[v]) {
            cost += c;
            adj[u].emplace_back(v, l);
            adj[v].emplace_back(u, l);
        }
    }
    cout << cost;

}

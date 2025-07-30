#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    unordered_map<int, vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    unordered_set<int> visited;
    queue<tuple<int, int>> q;
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int k;
        cin >> k;
        q.emplace(0, k);
    }
    int h = 0;
    while (!q.empty()) {
        auto [d, a] = q.front(); q.pop();
        if (visited.count(a)) continue;
        visited.insert(a);
        h = max(h, d);
        for (auto b : adj[a]) {
            if (!visited.count(b)) q.emplace(d+1, b);
        }
    }
    cout << h;
}
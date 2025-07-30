#include <vector>
#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int M, N;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
string out;

void dfs(int root, int depth = 0) {
    if (visited[root]) return;
    visited[root] = true;
    for (auto& [dest, i] : graph[root]) {
        if (!visited[dest]) {
            out[i] = depth % 2 == 0 ? 'R' : 'B';
            dfs(dest, depth + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    graph.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
    }

    visited.resize(N, false);
    out = string(M, 'G');
    for (int i = 0; i < N; i++) {
        dfs(i);
    }
    cout << out;
}
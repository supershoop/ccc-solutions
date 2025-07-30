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

vector<vector<ll>> dist;

ll N;

void bfs() {
    queue<tuple<ll, ll, ll>> q;
    q.emplace(0, 0, 0);
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        if (min(x, y) < 0 || max(x, y) >= N || dist[y][x] != LLONG_MAX) continue;
        dist[y][x] = d;
        q.emplace(x+2, y+1, d+1);
        q.emplace(x+2, y-1, d+1);
        q.emplace(x-2, y+1, d+1);
        q.emplace(x-2, y-1, d+1);
        q.emplace(x+1, y+2, d+1);
        q.emplace(x+1, y-2, d+1);
        q.emplace(x-1, y+2, d+1);
        q.emplace(x-1, y-2, d+1);
    }
}

int main() {
    cin >> N;
    dist.resize(N, vector(N, LLONG_MAX));
    bfs();

    for (auto& row : dist) {
        for (auto& v : row) {
            cout << v << ' ';
        }
        cout << '\n';
    }
}
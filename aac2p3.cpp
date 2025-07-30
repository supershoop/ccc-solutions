#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iterator>

using namespace std;

int N, M;

vector<string> grid;
vector<vector<int>> dist;

int distance(int x, int y) {
    if (x >= M || y >= N || x < 0 || y < 0) return 0;
    return dist[y][x];
}

int encode(int x, int y) {
    return x + y * M;
}

bool possible(int d) {
    queue<tuple<int, int>> q;
    q.emplace(M-1, N-1);
    int count = 0;
    vector visited(N*M, false);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int enc = encode(x, y);
        if (visited[enc]) continue;
        visited[enc] = true;
        int mX = 1;
        int mY = 0;
        if (x-d+1<=0 && y-d+1<=0) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int x2 = x+mX, y2 = y+mY;
            int d2 = distance(x2, y2);
            if (d2 >= d) {
                q.emplace(x2, y2);
            }
            mY *= -1;
            swap(mY, mX);
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    grid.resize(N);
    dist.resize(N, vector(M, -1));
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j]=='X') dist[i][j] = 0;
            else {
                int x = j == 0 ? 1 : dist[i][j-1] + 1;
                int y = i == 0 ? 1 : dist[i-1][j] + 1;
                int diag = (i == 0 || j == 0) ? 1 : dist[i-1][j-1] + 1;
                dist[i][j]=min({x, y, diag});
            }
        }
    }

    int low = 1, high = min(M-1, N-1);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (possible(mid))
            low = mid + 1;
        else
            high = mid-1;
    }

    cout << (possible(high+1) ? high+1 : high);
}
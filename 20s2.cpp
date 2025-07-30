#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstdint>
#include <list>
#include <unordered_set>
#include <list>

using namespace std;

using num = int_least16_t;

unordered_map<int, vector<num>> sieve;

void gen(num M, num N) {
    sieve.reserve(M*N/2);
    num v = min(M, N);
    num V = max(M, N);
    for (int i = 1; i <= v; i++) {
        for (int j = i; j <= V; j++) {
            sieve[i * j].emplace_back(j);
        }
    }
}
int P;
bool valid(int x) {
    return x <= P && sieve.count(x) && !sieve[x].empty() && sieve[x].front() != -1;
}

bool can_escape(int M, int N, vector<vector<int>>& v) {
    gen(M, N);
    P = M * N;
    queue<int> q;
    q.emplace(v[1][1]);
    while (!q.empty()) {
        auto val = q.front(); q.pop();
        if (!valid(val)) continue;
        for (const auto x2: sieve[val]) {
            num y2 = val / x2;
            if (y2 == M && x2 == N) return true;
            if (y2 == N && x2 == M) return true;
            if (y2 <= M && x2 <= N) {
                int val2 = v[y2][x2];
                if (val != val2 && valid(val2)) q.emplace(val2);
            }
            if (y2 <= N && x2 <= M) {
                int val2 = v[x2][y2];
                if (val != val2 && valid(val2)) q.emplace(val2);
            }

        }
        sieve[val].front() = -1;
    }
    return false;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector v(M+1, vector(N+1, 0));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> v[i][j];
        }
    }
    cout << (can_escape(M, N, v) ? "yes" : "no");
}
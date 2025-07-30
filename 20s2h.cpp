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
    return sieve.count(x) && !sieve[x].empty() && sieve[x].front() != -1;
}

bool can_escape(int M, int N, vector<vector<int>> v) {
    gen(M, N);
    P = M * N;
    queue<int> q;
    q.emplace(v[1][1]);
    while (!q.empty()) {
        auto val = q.front(); q.pop();
        if (!sieve.count(val)) continue;
        for (const auto x2: sieve[val]) {
            num y2 = val / x2;
            if (y2 == M && x2 == N) return true;
            if (y2 == N && x2 == M) return true;
            if (y2 <= M && x2 <= N) {
                int val2 = v[y2][x2];
                if (val != val2 && valid(val2)) {
                    q.emplace(val2);
                    sieve[val2].front() = -1;
                }
            }
            if (y2 <= N && x2 <= M) {
                int val2 = v[x2][y2];
                if (val != val2 && valid(val2)) {
                    q.emplace(val2);
                    sieve[val2].front() = -1;
                }
            }

        }
        sieve[val].front() = -1;
    }
    return false;
}

int main() {
    cout << can_escape(3, 4, {{0, 0, 0, 0, 0},
                  {0, 3, 10, 8, 1},
                  {0, 1, 11, 12, 12},
                  {0, 6, 2, 3, 9}});
    return 0;
}
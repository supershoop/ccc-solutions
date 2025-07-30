#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <set>

using namespace std;

vector<vector<int>> walkways;
vector<int> X;
vector<int> Y;
vector<int> S;
vector<int> StoI;

int N, W, D;
vector<int> t;
void bfs() {
    t.resize(N, INT_MAX);
    queue<pair<int, int>> q;
    q.emplace(0, N-1);
    t[N-1]=0;

    while (!q.empty()) {
        auto [time, s] = q.front(); q.pop();
        time = -time;
        for (auto dest : walkways[s]) {
            if (time+1 < t[dest]) {
                t[dest] = time + 1;
                q.emplace(-time-1, dest);
            }
        }
    }
}

int calc(int s) {
    if (t[s] == INT_MAX) return INT_MAX;
    return StoI[s] + t[s];
}

int main() {
    cin >> N >> W >> D;
    S.resize(N);
    StoI.resize(N);
    walkways.resize(N);
    X.resize(D);
    Y.resize(D);
    for (int i = 0; i < W; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        walkways[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        s--;
        S[i] = s;
        StoI[s] = i;
    }
    for (int i = 0; i < D; i++) {
        cin >> X[i];
        cin >> Y[i];
        X[i]--;
        Y[i]--;
    }
    multiset<int> dist;
    vector<int> cache(N);

    bfs();
    for (int i = 0; i < N; i++) {
        dist.insert(cache[S[i]] = calc(S[i]));
    }
    for (int d = 0; d < D; d++) {
        int& s1 = S[X[d]];
        int& s2 = S[Y[d]];
        dist.erase(dist.lower_bound(cache[s1]));
        dist.erase(dist.lower_bound(cache[s2]));
        swap(StoI[s1], StoI[s2]);
        swap(s1, s2);
        dist.insert(cache[s1] =  calc(s1));
        dist.insert(cache[s2] = calc(s2));
        cout << *dist.begin() << '\n';
    }
}
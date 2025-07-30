#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <set>
#include <unordered_map>

using ll = long long;
using namespace std;

vector<unordered_map<int, int>> tree;
vector<int> assign;
vector<bool> mark;

ll N, Q;
ll S;
int np2(int n) {
    n--;
    n |= n >> 16;
    n |= n >> 8;
    n |= n >> 4;
    n |= n >> 2;
    n |= n >> 1;
    return n + 1;
}

void push(int k) {
    if (k * 2 + 1 < S * 2 &&  assign[k] ) {
        assign[k*2] = assign[k*2+1] = assign[k];
        mark[k*2] = mark[k*2+1] = true;
    }
    assign[k] = 0;
}

int get(int a, int b, int v, int k, int x, int y) {
    if (b < x || a > y || k > S*2) return 0;
    if (a <= x && b >= y) {
        if (assign[k] && mark[k]) {
            tree[k] = {{ assign[k], (y-x) + 1}};
            mark[k] = false;
        }
        if (!mark[k]) return tree[k].count(v) ? tree[k][v] : 0;
    }
    push(k);
    int d = (x + y) / 2;
    int c = get(a, b, v, k*2, x, d) + get(a, b, v, k*2+1, d+1, y);
    tree[k].clear();
    for (auto& [key, val] : tree[k*2]) {
        tree[k][key] += val;
    }
    for (auto& [key, val] : tree[k*2+1]) {
        tree[k][key] += val;
    }
    mark[k] = false;
    return c;
}


void update(int a, int b, int v, int k, int x, int y) {
    if (b < x || a > y  || k > S*2) return;
    if (a <= x && b >= y) {
        assign[k] = v;
        mark[k] = true;
    } else {
        push(k);
        int d = (x + y) / 2;
        update(a, b, v, k*2, x, d);
        update(a, b, v, k*2+1, d+1, y);
        tree[k].clear();
        mark[k] = true;
    }
}

int main() {
    cin >> N >> Q;
    S = np2(N);
    tree.resize(S*2+1);
    assign.resize(S*2+1, 0);
    mark.resize(S*2+1, true);

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        update(i+1, i+1, v, 1, 1, S);
    }

    for (int i = 0; i < Q; i++) {
        int t, l, r, v;
        cin >> t >> l >> r >> v;
        if (t == 1) {
            update(l, r, v, 1, 1, S);
        } else {
            cout << get(l, r, v, 1, 1, S) << '\n';
        }
    }

}
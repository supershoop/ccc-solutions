#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

vector<int> trees[32];
vector<bool> bits[32];
int N, Q;

int count(int bit, int i) {
    int sum = 0;
    int k = i;
    while (k >= 1) {
        sum += trees[bit][k];
        k-=k&-k;
    }
    return sum;
}

void set(int i, int n) {
    for (int b = 0; b < 32; b++) {
        bool bit = (n >> b) & 1;
        int diff = static_cast<int>(bit) - static_cast<int>(bits[b][i]);
        bits[b][i] = bit;
        int k = i;
        while (k <= N) {
            trees[b][k]+=diff;
            k+=k&-k;
        }
    }
}

int main() {
    cin >> N >> Q;
    for (auto& tree : trees) tree.resize(N+1, 0);
    for (auto& bitset : bits) bitset.resize(N+1, false);

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        set(i, x);
    }

    for (int i = 0; i < Q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            set(l, r);
        } else {
            ll total = 0;
            for (int bit = 0; bit < 32; bit++) {
                ll num = count(bit, r) - count(bit, l-1);
                switch (t) {
                    case 2:
                        total += ((num) * (r-l) - (num) * (num - 1) / 2) * (1ll << bit);
                        break;
                    case 3:
                        total += ((num) * (num - 1) / 2) * (1ll << bit);
                        break;
                    case 4:
                        total += ((num) * (r - l + 1- num)) * (1ll << bit);
                        break;
                }
            }
            cout << total << '\n';
        }
    }
}
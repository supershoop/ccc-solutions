#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <cmath>
#include <array>

using namespace std;

int N;
int M;
int main() {
    int row = 0;
    int count = 0;
    vector<array<int, 2>> bus;
    cin >> N >> M;
    bus.resize(N, {1, 1});
    bool valid = true;
    for (int i = 1; i <= 2 * M * N; i++) {
        int s;
        cin >> s;
        int r = s / (M * 2);
        int c = s % (M * 2);
        if (c == 0) {
            r--;
            c = (M * 2);
        }
        int side = 0;
        if (c > M) {
            c -= M;
            side = 1;
        } else {
            c = M + 1 - c;
        }
        if (r > row) {
            valid = false;
            break;
        }
        if (bus[row][side] != c) {
            valid = false;
            break;
        }
        bus[row][side]++;
        count++;
        if (count == 2 * M) {
            count = 0;
            row++;
        }
    }
    cout << (valid ? "yes" : "no");
}
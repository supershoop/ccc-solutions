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
#include <string>

using namespace std;

vector<bool> lights;
vector<int> dist;
set<int> mis;
int N, K;
int main() {
    string s;
    cin >> N >> K >> s;
    lights.reserve(N);
    for (auto ch : s) {
        lights.push_back(ch == '1');
    }

    int last = -1;
    dist.resize(N);
    for (int i = 0; i < N; i++) {
        if (lights[i]) last = i;
        dist[i] = (last == -1) ? INT_MAX : (i - last);
    }
    last = -1;
    for (int i = N-1; i >= 0; i--) {
        if (lights[i]) last = i;
        dist[i] = min(dist[i], (last == -1) ? INT_MAX : (last-i));
    }
    for (int i = 0; i < N; i++) {
        if (dist[i] > K) mis.insert(i);
    }
    int count = 0;
    while (!mis.empty()) {
        count++;
        int index = (*mis.begin()) + 2 * K + 1;
        mis.erase(mis.begin(), mis.lower_bound(index));
    }
    cout << count;

}
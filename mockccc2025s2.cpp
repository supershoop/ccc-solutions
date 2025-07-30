#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using ll = long long;
using namespace std;

vector<int> A, B;
int N;
unordered_map<int, unordered_set<int>> indices;
int main() {
    cin >>  N;
    A.resize(N);
    B.resize(N);
    vector<int> mismatch;
    vector<pair<int, int>> swaps;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            indices[A[i]].insert(i);
            mismatch.push_back(i);
        }
    }

    for (auto i : mismatch) {
        if (A[i] != B[i]) {
            int j = *indices[B[i]].begin();
            swaps.emplace_back(i, j);
            indices[A[i]].erase(i);
            swap(A[i], A[j]);
            indices[B[i]].erase(j);
            if (A[j] != B[j]) indices[A[j]].insert(j);
        }
    }
    cout << swaps.size() << '\n';
    for (auto& [ i, j ] : swaps) {
        cout << i + 1<< ' ' << j + 1<< '\n';
    }
}
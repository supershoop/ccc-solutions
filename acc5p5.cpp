#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector link(N, 0);
    vector<int> count;
    vector<int> children(N, 0);
    vector<int> nodes(N);
    int A = 0;
    for (int i = 1; i < N; i++) {
        int x;
        cin >> x;
        x--;
        link[i] = link[x]+1;
        children[x]++;
        nodes[i] = x;
    }
    for (int i = 1; i < N; i++) {
        if (children[nodes[i]] <= 1) continue;
        if (link[i] < count.size()) {
            count[link[i]]++;
        } else {
            count.resize(link[i]+1, 0);
            count[link[i]] = 1;
        }
        A = max(A, count[link[i]]);
    }
    cout << A+1 << '\n';
}
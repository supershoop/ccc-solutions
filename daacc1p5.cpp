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
#include <iterator>
#include <algorithm>

using namespace std;
int N;
string A, B;
tuple<int, int, int> correct[4];
int knownCount[4];
int main() {
    cin >> N >> A >> B;
    B = "";
    int incorrect = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == B[i]) incorrect++;
    }
    int x, y, z, a;
    cin >> x >> y >> z >> a;
    cout << incorrect;
}
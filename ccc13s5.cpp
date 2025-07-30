#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cost = 0;
    while (n != 1   ) {
        for (int f = 2; f <= n; f++) {
            if (n % f == 0) {
                cost += (n-(n/f)) / (n/f);
                n -= n/f;
                break;
            }
        }
    }
    cout << cost;
}
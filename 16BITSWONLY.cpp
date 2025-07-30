#include <iostream>
#include <cstdint>

using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int64_t P, a, b;
        cin >> a >> b >> P;

        cout << (a * b == P ? "POSSIBLE DOUBLE SIGMA\n" : "16 BIT S/W ONLY\n");

    }
}
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int C;
    cin >> C;
    for (int i = 0; i < C; i++) {
        int N, W, H;
        cin >> N >> W >> H;
        int ans = INT_MAX;
        for (int width = 1; width <= N; width++) {
            if (N%width != 0) continue;
            int height = N / width;
            ans = min(ans, 2 * W * width + 2 * H * height);
        }
        for (int width = 1; width <= N; width++) {
            if (N%width != 0) continue;
            int height = N / width;
            ans = min(ans, 2 * W * width + 2 * H * height);
        }
        for (int width = 1; width <= N; width) {
            if (((N-width) * H) % (width * W) != 0) continue;

        }

        cout << ans << '\n';
    }
}
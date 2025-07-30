#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <tuple>

using namespace std;

int T;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        string num;
        vector<pair<int, int>> digits;
        cin >> num;
        for (int i = 0; i < num.size(); i++) {
            int digit = num[num.size()-1-i] - '1' + 1;
            digits.emplace_back(i, digit);
        }
        for (auto& [_, digit] : digits) {
            cout << digit;
        }
        cout << '\n';
    }
}
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <string>

using ll = long long;
using namespace std;

string s;
int main() {
    cin >> s;
    map<char, ll> chars;
    for (auto ch : s) {
        chars[ch]++;
    }

    char odd = 0;
    vector<char> ord;
    string out;
    for (auto& [ch, count] : chars) {
        if (count%2 == 1) {
            if (!odd) odd = ch;
            else {
                cout << "NO SOLUTION";
                exit(0);
            }
        } else {
            for (ll i = 0; i < count/2; i++) {
                out.push_back(ch);
            }
        }
    }
    string rev = out;
    reverse(rev.begin(), rev.end());
    if (odd) out.append(string(chars[odd], odd));
    out.append(rev);
    cout << out;

}
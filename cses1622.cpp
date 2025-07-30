#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <iterator>
#include <iterator>
#include <string>

using ll = long long;
using namespace std;

vector<string> results;
string s;
int chars[26];

void run(string prev, int i = 0) {
    int chars2[26];
    fill(std::begin(chars2), std::end(chars2), 0);
    for (char c : prev) {
        chars2[c-'a']++;
    }
    for (char c = 0; c < 26; c++) {
        if (chars[c]-chars2[c] > 0) {
            string n = prev + (char) (c + 'a');
            if (i+1==s.size()) results.emplace_back(n);
            else run(n, i+1);
        }
    }
}

int main() {
    fill(std::begin(chars), std::end(chars), 0);
    getline(cin, s);

    for (char c : s) {
        chars[c-'a']++;
    }

    run("");
    cout << results.size() << '\n';
    for (const string& r : results) cout << r << '\n';
}
#include <vector>
#include <iostream>
#include <string>
#include <climits>

using namespace std;
using ll = long long;

const ll A = 0;
const ll B = 1;
const ll C = 2;

vector<ll> N[3];

string table;
ll num[3] = {0, 0, 0};

ll getCount(ll type, ll begin, ll end) {
    if (begin <= end) {
        return N[type][end] - N[type][begin];
    } else {
        return N[type][end] + num[type] - N[type][begin];
    }
}

int main() {
    cin >> table;
    for (char x : table) {
        if (x == 'A') num[A]++;
        if (x == 'B') num[B]++;
        if (x == 'C') num[C]++;
        N[A].push_back(num[A]);
        N[B].push_back(num[B]);
        N[C].push_back(num[C]);
    }
    ll answer = INT_MAX;
    for (ll i = 0; i < table.size(); i++) {
        ll aEnd = (i + num[A]) % table.size();
        ll nonA = getCount(B, i, aEnd) + getCount(C, i, aEnd);
        // ABC
        ll bEnd = (aEnd + num[B]) % table.size();
        ll nonB = getCount(A, aEnd, bEnd) + getCount(C, aEnd, bEnd);
        ll AB = getCount(A, aEnd, bEnd);
        ll BA = getCount(B, i, aEnd);
        answer = min(answer, nonA + nonB - min(AB, BA));
        // ACB
        ll bBeg = (aEnd + num[C]) % table.size();
        bEnd = (bBeg + num[B]) % table.size();
        nonB = getCount(A, bBeg, bEnd) + getCount(C, bBeg, bEnd);
        AB = getCount(A, bBeg, bEnd);
        BA = getCount(B, i, aEnd);
        answer = min(answer, nonA + nonB - min(AB, BA));

    }
    cout << answer;
}
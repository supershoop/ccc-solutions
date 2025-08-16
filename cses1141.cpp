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

map<ll, ll> lastPos;
ll N;

int main() {
    cin >> N;
    ll maxLen=0;
    ll pos=-1;
    for (ll i = 0; i < N; i++) {
        ll song;
        cin >> song;
        if (lastPos.count(song)) pos=max(pos, lastPos[song]);
        lastPos[song]=i;
        maxLen = max(i-pos, maxLen);
    }
    cout << maxLen;

}
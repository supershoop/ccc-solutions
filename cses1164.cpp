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

ll N;

vector<tuple<ll, ll, ll>> guests;
vector<ll> rooms;

int main() {
    cin >> N;
    rooms.resize(N);
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        guests.emplace_back(x, y, i);
    }
    sort(guests.begin(), guests.end());
    priority_queue<pair<ll, ll>> q; // -y, room
    q.emplace(0, 1);
    for (const auto& [x, y, i] : guests) {
        ll room;
        if (-q.top().first < x) {
            room = q.top().second;
            q.pop();
        } else {
            room = q.size()+1;
        }
        rooms[i]=room;
        q.emplace(-y, room);
    }
    cout << q.size() << '\n';
    for (const auto x : rooms) {
        cout << x << ' ';
    }

}

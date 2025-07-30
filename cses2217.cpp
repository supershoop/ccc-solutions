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

vector<ll> mapping;
vector<ll> vec;
vector<ll> rounds;

ll N, M;

ll solve() {
    ll C=1;
    for (ll i = 1; i < N; i++) {
        if (mapping[i]<mapping[i-1]) C++;
    }
    return C;
}

int main() {
    cin >> N >> M;
    mapping.resize(N);
    rounds.resize(N);
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        x--;
        mapping[x]=i;
        vec.push_back(x);
    }
    ll C=solve();
    for (ll i = 0; i < M; i++) {
        ll a, b, x, y;
        cin >> x >> y;
        x--, y--;
        a = vec[x], b=vec[y];
        if (a!=0 && mapping[a]<mapping[a-1]) C--;;
        if (b!=0 && b-1!=a && mapping[b]<mapping[b-1]) C--;
        if (a<N-1 && mapping[a]>mapping[a+1]) C--;
        if (b<N-1 && b+1!=a && mapping[b]>mapping[b+1]) C--;
        swap(vec[x], vec[y]);
        swap(mapping[a], mapping[b]);
        if (a!=0 && mapping[a]<mapping[a-1]) C++;
        if (b!=0 && b-1!=a && mapping[b]<mapping[b-1]) C++;
        if (a<N-1 && mapping[a]>mapping[a+1]) C++;
        if (b<N-1 && b+1!=a && mapping[b]>mapping[b+1]) C++;
        cout << C << '\n';
    }

}
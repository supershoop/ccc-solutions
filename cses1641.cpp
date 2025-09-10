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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using ll = unsigned int;
using namespace std;

ll N, X;

map<ll, ll> s;
vector<ll> A;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    A.resize(N);
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        A[i]=x;
        s[x]=i;
    }
    for (ll i = 0; i < N; i++) {
        ll x = A[i];
        for (ll j = i+1; j < N; j++) {
            ll y = A[j];
            auto iter = s.find(X-x-y);
            if (iter != s.end()) {
                ll k = iter->second;
                if (i==k || j==k) continue;
                printf("%d %d %d", i+1, j+1, k+1);
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";

}
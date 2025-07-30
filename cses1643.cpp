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

vector<ll> arr;
ll N;

int main() {
    cin >> N;
    arr.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ll C=arr[0], sum=arr[0];
    for (ll i = 1; i < N; i++) {
        sum = max(arr[i], sum+arr[i]);
        C=max(C, sum);
    }
    cout << C;


}
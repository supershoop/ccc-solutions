#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
// Source: https://usaco.guide/general/io

using namespace std;

int a, b, c, d;
double v1, v2, v3;
vector<pair<double,double>> circles;
vector<int> possiblescores;
vector<int> hits;
double previous = -1;
int ofindex = 0;

int binarysearch(int low, int high, double target){
    while (low <= high){
        int mid = (high + low)/2;
        if (circles[mid].first < target && circles[mid].second >= target){
            return mid;
        }

        if (circles[mid].second < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    cin >> a >> b;
    hits.resize(a,0);
    possiblescores.resize(a,0);
    for (int i = 0; i < a; i++){
        cin >> v3;
        v3 = v3*v3;
        circles.push_back({previous, v3});
        previous = v3;
    }

    for (int i = 0; i < a; i++){
        cin >> possiblescores[i];
    }

    for (int i = 0; i < b; i++){
        cin >> v1 >> v2;
        ofindex = binarysearch(0, a - 1, v1*v1 + v2*v2);
        if (ofindex != -1){
            hits[ofindex] += 1;
        }
    }

    sort(hits.begin(),hits.end());
    sort(possiblescores.begin(), possiblescores.end());


    int lowestscore = 0;
    int highestscore = 0;
    for (int i = 0; i < a; i++){
        highestscore += hits[i]*possiblescores[i];
        lowestscore += hits[i]*possiblescores[a - i - 1];
    }

    cout << lowestscore << endl << highestscore;
}
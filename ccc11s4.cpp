#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <array>

using namespace std;
vector<vector<int>> graph;
vector<int> patients;

// O-, O+, A-, A+, B-, B+, AB-, AB+
vector<vector<int>> compatibility = {
    {0, 1, 2, 3, 4, 5, 6, 7 }, // O-
    {1, 3, 5, 7}, // O+
    {2, 3, 6, 7}, // A-
    {3, 7}, // A+
    {4, 5, 6, 7}, // B-
    {5, 7}, // B+
    {6, 7}, // AB-
    {7}, // AB+
};

int flow = 0;

vector<int> parent(18);

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    array<bool, 18> visited{};
    fill(visited.begin(), visited.end(), false);
    visited[0] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            if (graph[x][i] > 0) {
                if (visited[i]) continue;
                visited[i] = true;
                q.push(i);
                parent[i] = x;
                if (i == 17) return true;
            }
        }
    }
    return false;
}

int maxFlow() {
    int total = 0;
    while (bfs(0)) {
        int flow = INT_MAX;
        int to = 17;
        while (to != 0) {
            int from = parent[to];
            flow = min(flow, graph[from][to]);
            to = from;
        }
        to = 17;
        while (to != 0) {
            int from = parent[to];
            graph[from][to] -= flow;
            graph[to][from] += flow;
            to = from;
        }
        total += flow;
    }
    return total;
}

int main() {
    graph.resize(18, vector(18, 0));
    patients.resize(8);
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        graph[0][i+1] = x;
    }
    for (int i = 0; i < 8; i++) {
        cin >> patients[i];
    }
    for (int from = 0; from < 8; from++) {
        for (auto to : compatibility[from]) {
            graph[from+1][to+9] = INT_MAX;
        }
    }
    for (int i = 0; i < 8; i++) {
        graph[i+9][graph.size()-1] = patients[i];
    }
    cout << maxFlow();
}
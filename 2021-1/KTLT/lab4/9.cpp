#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        compare
    > pq;
    
    // setup dist and pq
    vector<int> dist(adj.size());
    dist[0] = 0;
    for (int i = 1; i < (int) dist.size(); i++) dist[i] = INT_MAX;
    for (int i = 0; i < (int) dist.size(); i++) pq.push({ i, dist[i] });

    while (!pq.empty()) {
        pair<int, int> top = pq.top(); pq.pop();

        for (auto v: adj[top.first]) {
            if (dist[v.first] > dist[top.first] + v.second) {
                dist[v.first] = dist[top.first] + v.second;
                pq.push({ v.first, dist[v.first] });
            }
        }
    }

    return dist;
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}
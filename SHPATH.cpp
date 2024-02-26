#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

const int MAX_COST = 200000;

struct Edge {
    int to, cost;
    Edge(int _to, int _cost) : to(_to), cost(_cost) {}
};

// Dijkstra's algorithm to find the shortest path from a starting node to all other nodes
vector<int> dijkstra(int start, const vector<vector<Edge>>& adj_list) {
    vector<int> dist(adj_list.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& e : adj_list[u]) {
            int v = e.to;
            int w = e.cost;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist;
}

int main() {
    int s;
    cin >> s;

    for (int t = 0; t < s; t++) {
        int n;
        cin >> n;

        unordered_map<string, int> city_to_index;
        vector<vector<Edge>> adj_list(n);

        // Read in the graph edges and their costs
        for (int i = 0; i < n; i++) {
            string city;
            cin >> city;
            city_to_index[city] = i;

            int p;
            cin >> p;

            for (int j = 0; j < p; j++) {
                int neighbor_index, cost;
                cin >> neighbor_index >> cost;
                neighbor_index--;

                adj_list[i].push_back({ neighbor_index, cost });
            }
        }

        // Find the shortest paths between each pair of cities using Dijkstra's algorithm
        int r;
        cin >> r;

        for (int i = 0; i < r; i++) {
            string source, dest;
            cin >> source >> dest;
            int start = city_to_index[source];
            int end = city_to_index[dest];

            vector<int> dist = dijkstra(start, adj_list);
            int shortest_path = dist[end];

            if (shortest_path > MAX_COST) {
                cout << "NO PATH" << endl;
            } else {
                cout << shortest_path << endl;
            }
        }

        if (t != s - 1) {
            string separator;
            cin >> separator;
        }
    }

    return 0;
}


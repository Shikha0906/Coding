#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // Create adjacency list: u -> {v, weight}
        vector<vector<pair<int, int>>> adj(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 0}); // Original edge costs 0 reversals
            adj[v].push_back({u, 1}); // Reversed edge costs 1 reversal
        }

        // 0-1 BFS implementation
        vector<int> dist(n + 1, 1e9);
        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            if (u == dst) return dist[dst];

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    if (weight == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
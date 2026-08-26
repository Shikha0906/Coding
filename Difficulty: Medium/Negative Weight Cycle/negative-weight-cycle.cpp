class Solution {
  public:
    int isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<int> dist(V, 1e9);
        dist[0] = 0;

        // Relax all edges V - 1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // 100th check: if we can still relax, a negative cycle exists
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] + weight < dist[v]) {
                return 1; // Negative cycle found
            }
        }

        return 0; // No negative cycle
    }
};
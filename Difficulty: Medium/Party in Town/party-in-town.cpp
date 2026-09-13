class Solution {
private:
    pair<int, int> bfs(int startNode, int n, const vector<vector<int>>& adj) {
        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(startNode);
        dist[startNode] = 0;

        int farthestNode = startNode;
        int maxDist = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > maxDist) {
                maxDist = dist[u];
                farthestNode = u;
            }

            for (int v : adj[u - 1]) { // adj is 0-indexed for houses 1 to n
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return {farthestNode, maxDist};
    }

public:
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();
        if (n <= 1) return 0;

        // 1. Find one endpoint of the diameter
        pair<int, int> p1 = bfs(1, n, adj);

        // 2. Find the other endpoint and the diameter length
        pair<int, int> p2 = bfs(p1.first, n, adj);

        int diameter = p2.second;

        // The minimum radius of the tree is ceiling(diameter / 2)
        return (diameter + 1) / 2;
    }
};
class Solution {
    public int[] maxDistance(int V, int src, ArrayList<ArrayList<Integer>> edges) {
        
        // Adjacency list
        ArrayList<ArrayList<int[]>> adj = new ArrayList<>();
        
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (ArrayList<Integer> edge : edges) {
            int u = edge.get(0);
            int v = edge.get(1);
            int w = edge.get(2);
            
            adj.get(u).add(new int[]{v, w});
        }
        
        // Topological Sort
        boolean[] visited = new boolean[V];
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoSort(i, adj, visited, stack);
            }
        }
        
        // Initialize distance
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MIN_VALUE);
        dist[src] = 0;
        
        // Process nodes in topological order
        while (!stack.isEmpty()) {
            int u = stack.pop();
            
            if (dist[u] == Integer.MIN_VALUE) {
                continue;
            }
            
            for (int[] edge : adj.get(u)) {
                int v = edge[0];
                int weight = edge[1];
                
                dist[v] = Math.max(dist[v], dist[u] + weight);
            }
        }
        
        return dist;
    }
    
    private void topoSort(int node,
                          ArrayList<ArrayList<int[]>> adj,
                          boolean[] visited,
                          Stack<Integer> stack) {
        
        visited[node] = true;
        
        for (int[] edge : adj.get(node)) {
            int next = edge[0];
            
            if (!visited[next]) {
                topoSort(next, adj, visited, stack);
            }
        }
        
        stack.push(node);
    }
}
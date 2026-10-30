class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
       // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // Priority Queue stores: {distance, node, consecutive_label_count}
        // Using greater<> ensures min-heap extraction
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // dist[u][cnt]: minimum distance to reach node u with a current label streak of cnt
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int d = curr[0];
            int u = curr[1];
            int cnt = curr[2];
            
            // Stale state check
            if (d > dist[u][cnt]) {
                continue;
            }
            
            // First time reaching destination guarantees minimum cost
            if (u == n - 1) {
                return d;
            }
            
            for (const auto& [v, w] : graph[u]) {
                // Determine new consecutive streak
                int nextCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;
                
                // Prune if streak exceeds the allowed limit k
                if (nextCnt > k) {
                    continue;
                }
                
                // Relaxation step
                if (dist[v][nextCnt] > d + w) {
                    dist[v][nextCnt] = d + w;
                    pq.push({dist[v][nextCnt], v, nextCnt});
                }
            }
        }
        
        return -1; 
    }
};
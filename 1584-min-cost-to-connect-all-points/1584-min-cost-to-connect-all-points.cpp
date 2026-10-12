class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            min_heap;

        min_heap.push({0, 0}); // weight,node

        vector<bool> vis(n, false);

        int min_cost = 0;

        while (!min_heap.empty()) {
            pair<int, int> p = min_heap.top();
            int weight = p.first;
            int node = p.second;

            min_heap.pop();

            if(vis[node]==true)
            continue;

             vis[node] = true;
            min_cost += weight;

            for (auto& neigh : adj[node]) {
                int adj = neigh.first;
                int wt = neigh.second;

                if (vis[adj] == false)
                    min_heap.push({wt, adj});
            }
        }

        return min_cost;
    }
};
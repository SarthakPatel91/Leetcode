class Solution {
public:
    typedef tuple<int, int, int> t;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        int m = edges.size();
        vector<vector<pair<int, int>>> adj(n);

        if (n == 1)
            return 0;

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        priority_queue<t, vector<t>, greater<t>> min_heap;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[0][1] = 0;
        min_heap.push({0, 0, 1}); // wt,node,count;

        while (!min_heap.empty()) {
            auto [d, node, count] = min_heap.top();
            min_heap.pop();

            if (d < dist[node][count])
                continue;

            if (node == n - 1)
                return d;

            for (auto& vec : adj[node]) {
                int adjNode = vec.first;
                int wt = vec.second;

                int newCount =
                    (labels[adjNode] == labels[node]) ? count + 1 : 1;
                if (newCount > k)
                    continue;

                int newDist = d + wt;

                if (newDist < dist[adjNode][newCount]) {
                    dist[adjNode][newCount] = newDist;
                    min_heap.push({newDist, adjNode, newCount});
                }
            }
        }
        return -1;
    }
};
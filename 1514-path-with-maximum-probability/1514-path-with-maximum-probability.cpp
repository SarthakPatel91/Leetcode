class Solution {
public:
    typedef double db;
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        int m = edges.size();
        // int n = edges[0].size();

        if (start_node == end_node)
            return 1.0;

        // make graph---undirected
        vector<vector<pair<int, db>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        // use dijkstra but maximize the path probab
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        priority_queue<pair<db, int>> minheap;
        minheap.push({1.0, start_node});

        while (!minheap.empty()) {
            db d = minheap.top().first;
            int node = minheap.top().second;
            minheap.pop();
            for (auto& v : adj[node]) {
                db adjnode = v.first;
                db wt = v.second;
                db newprob = d * wt;
                if (newprob > dist[adjnode]) {
                    dist[adjnode] = newprob;
                    minheap.push({newprob, adjnode});
                }
            }
        }

        return dist[end_node];
    }
};
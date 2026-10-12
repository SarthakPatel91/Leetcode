class Solution {
public:
    int isolated_cluster = 0;

    void countClusters(int n, vector<vector<int>>& adj, vector<bool>& vis,
                       int node) {
        if (vis[node] == true)
            return;

        vis[node] = true;

        for (auto& neigh : adj[node]) {
            if (vis[neigh] == false) {
                countClusters(n, adj, vis, neigh);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if(vis[i]==false)
            isolated_cluster++;

            countClusters(n, adj, vis, i);
            
        }

        int edges = m;

        if (edges < n - 1)
            return -1;

        return isolated_cluster-1;
    }
};
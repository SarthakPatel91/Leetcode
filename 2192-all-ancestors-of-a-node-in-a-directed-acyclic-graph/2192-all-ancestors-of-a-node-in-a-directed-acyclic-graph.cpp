class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,
             vector<int>& ds) {
        if (vis[node] == true)
            return;

        vis[node] = true;

        for (auto& neig : adj[node]) {
            if (vis[neig] == false) {
                ds.push_back(neig);
                dfs(neig, adj, vis, ds);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // graph with reversed edges
        int m = edges.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            // reversed edges
            adj[v].push_back(u);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            vector<int> ds;

            dfs(i, adj, vis, ds);
            sort(ds.begin(),ds.end());
            ans.push_back(ds);
        }

        return ans;
    }
};
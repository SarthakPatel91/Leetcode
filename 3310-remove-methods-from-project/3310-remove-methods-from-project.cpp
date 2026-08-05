class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (int next : adj[node]) {
            if (!vis[next])
                dfs(next, adj, vis);
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        int size = invocations.size();

        for (int i = 0; i < size; i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
        }

        vector<bool> vis(n, false);

        dfs(k, adj, vis);

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;

                for (int i = 0; i < n; i++)
                ans.push_back(i);

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};
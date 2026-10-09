
class Solution {
public:
    void countEdges(vector<vector<int>>& adj, vector<bool>& vis, int node,
                    int& v, int& e) {
        vis[node] = true;
        v++;
        e += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                countEdges(adj, vis, nei, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int v = 0, e = 0;
                countEdges(adj, vis, i, v, e);
                e /= 2;

                if (e == v * (v - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& ds,
             vector<vector<int>>& ans, vector<bool>& vis, int n) {
        if (node == n - 1) {
            ds.push_back(node);
            ans.push_back(ds);
            return;
        }

        vis[node] = true;
        ds.push_back(node);

        for (auto& neig : graph[node]) {
            if (vis[neig] == false) {
                dfs(neig, graph, ds, ans, vis, n);
                ds.pop_back();
                vis[neig] = false;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = graph.size();
        vector<bool> vis(n, false);

        dfs(0, graph, ds, ans, vis, n);

        return ans;
    }
};
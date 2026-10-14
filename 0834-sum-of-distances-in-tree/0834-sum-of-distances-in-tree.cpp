class Solution {
public:
    vector<int> ans, cnt;

    void dfs1(int node, int par, vector<vector<int>>& adj, int d) {
        cnt[node] = 1;
        ans[0] += d;

        for (int neig : adj[node]) {
            if (neig == par) continue;
            dfs1(neig, node, adj, d + 1);
            cnt[node] += cnt[neig];
        }
    }

    void dfs2(int node, int par, vector<vector<int>>& adj, int n) {
        for (int neig : adj[node]) {
            if (neig == par) continue;
            ans[neig] = ans[node] - cnt[neig] + (n - cnt[neig]);
            dfs2(neig, node, adj, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ans.assign(n, 0);
        cnt.assign(n, 0);

        dfs1(0, -1, adj, 0);
        dfs2(0, -1, adj, n);

        return ans;
    }
};
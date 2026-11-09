class Solution {
public:
    typedef long long ll;
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> subsize(n);
        vector<vector<ll>> dp(n, vector<ll>(3, INT_MAX));

        function<void(int, int)> dfs = [&](int s, int p) {
            subsize[s] = 1;
            for (auto u : adj[s]) {
                if (u == p)
                    continue;
                dfs(u, s);
                subsize[s] += subsize[u];
            }

            if (colors[s] == 'B')
                dp[s][0] = 0, dp[s][1] = subsize[s], dp[s][2] = 0;
            else
                dp[s][1] = 0, dp[s][0] = subsize[s], dp[s][2] = subsize[s];

            for (auto u : adj[s]) {
                if (u == p)
                    continue;
                dp[s][0] += dp[u][0];
            }

            for (auto u : adj[s]) {
                if (u == p)
                    continue;
                dp[s][1] += min(dp[u][0], dp[u][1]);
            }

            ll allblue = 0, atmostonered = 0;

            for (auto u : adj[s]) {
                if (u == p)
                    continue;
                atmostonered = min(allblue + min(dp[u][1], dp[u][2]),
                                   atmostonered + dp[u][0]);
                allblue += dp[u][0];
            }
            dp[s][2] += min(atmostonered, allblue);
        };
        dfs(0, -1);

        return *min_element(dp[0].begin(), dp[0].end());
    }
};
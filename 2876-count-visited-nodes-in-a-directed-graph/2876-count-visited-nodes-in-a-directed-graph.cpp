class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n, 0), vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (ans[i]) continue;

            vector<int> path;
            int node = i;

            while (!ans[node] && vis[node] == 0) {
                vis[node] = i + 1;
                path.push_back(node);
                node = edges[node];
            }

            int k = path.size() - 1;

            if (ans[node]) {
                int count = ans[node];
                while (k >= 0)
                    ans[path[k--]] = ++count;
            } else {
                int j = 0;
                while (path[j] != node) j++;

                int cycle = path.size() - j;

                for (int p = j; p < path.size(); p++)
                    ans[path[p]] = cycle;

                int count = cycle;
                for (int p = j - 1; p >= 0; p--)
                    ans[path[p]] = ++count;
            }

            for (int x : path) vis[x] = 0;
        }

        return ans;
    }
};
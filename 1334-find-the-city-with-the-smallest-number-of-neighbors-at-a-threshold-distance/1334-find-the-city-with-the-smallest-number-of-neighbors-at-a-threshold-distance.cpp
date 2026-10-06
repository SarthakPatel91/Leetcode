class Solution {
public:
    typedef long long ll;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<ll>> grid(n, vector<ll>(n, INT_MAX));

        for (int i = 0; i < n; i++)
            grid[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            grid[u][v] = wt;
            grid[v][u] = wt;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }

        int ans = -1;
        int minCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minCount) {
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};
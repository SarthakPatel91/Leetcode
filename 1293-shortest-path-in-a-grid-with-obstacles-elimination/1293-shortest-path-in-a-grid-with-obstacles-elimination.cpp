class Solution {
public:
    typedef tuple<int,int, int, int> t;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        dist[0][0][0] = 0; // i,j,count
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({0, 0, 0, 0}); // distance,(node->i,j),count

        while (!pq.empty()) {
            auto [d, i, j, count] = pq.top();
            pq.pop();

            if (i == m - 1 && j == n - 1)
                return d;

            for (int l = 0; l < 4; l++) {
                int nr = i + dr[l], nc = j + dc[l];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newRemoved = count + grid[nr][nc];
                if (newRemoved > k)
                    continue;

                int newDist = d+1;
                if (newDist < dist[nr][nc][newRemoved]) {
                    dist[nr][nc][newRemoved] = newDist;
                    pq.push({newDist, nr, nc, newRemoved});
                }
            }
        }
        return -1;
    }
};
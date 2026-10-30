class Solution {
public:
    typedef tuple<int, int, int> t;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0; // i,j
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({0, 0, 0}); // time,i,j

        while (!pq.empty()) {
            auto [time, i, j] = pq.top();
            pq.pop();

            if (time > dist[i][j])
                continue;

            if (i == n - 1 && j == m - 1)
                return time;

            for (int l = 0; l < 4; l++) {
                int nr = i + dr[l];
                int nc = j + dc[l];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int newTime = max(time, moveTime[nr][nc]) + 1;
                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, nr, nc});
                }
            }
        }
        return -1;
    }
};
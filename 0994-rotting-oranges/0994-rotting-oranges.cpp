class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        int count1 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    count1++;
                }
            }
        }

        if (count1 == 0)
            return 0;

        int time = 0;
        int newcount1 = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int k = 0; k < size; k++) {
                pair<int, int> p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();

                for (auto& dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                        grid[new_i][new_j] == 1) {

                        newcount1++;
                        grid[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                    }
                }
            }
            if (!q.empty())
                time++;
        }

        if (count1 == newcount1)
            return time;

        return -1;
    }
};
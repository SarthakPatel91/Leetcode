class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        if(q.size()==0 || q.size()==n*n)
        return -1;
        
        int res = -1;

        while (!q.empty()) {
            int size = q.size();
            res++;

            for (int k = 0; k < size; k++) {
                pair<int, int> p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();

                for (auto& dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
                        grid[new_i][new_j] == 0) {
                        grid[new_i][new_j] = 1;
                        q.push({new_i, new_j});
                    }
                }
            }
        }

        return res;
    }
};
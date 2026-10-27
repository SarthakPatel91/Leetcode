class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));

        // first row
        for (int j = 0; j < n; j++) {
            ans[0][j] = '.';
        }
        // last col
        for (int i = 0; i < m; i++) {
            ans[i][n - 1] = '.';
        }

        return ans;
    }
};
class Solution {
public:
    int m, n;
    bool valid(int idx, int jdx, vector<vector<int>>& mat) {

        int rowcount = 0;
        int colcount = 0;

        // int i = idx, j = jdx;
        // check in row
        for (int j = 0; j < n; j++) {
            if (mat[idx][j] == 1)
                rowcount++;
        }

        // check in col
        for (int i = 0; i < m; i++) {
            if (mat[i][jdx] == 1)
                colcount++;
        }

        if (rowcount > 1 || colcount > 1)
            return false;

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && valid(i, j, mat))
                    count++;
            }
        }

        return count;
    }
};
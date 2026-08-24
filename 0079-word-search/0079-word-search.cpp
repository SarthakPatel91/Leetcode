class Solution {
public:
    int m, n;
    bool dfs(int r, int c, int idx, string& word, vector<vector<char>>& board) {
        if (idx == word.size()) {
            return true;
        }

        if (r < 0 || r >= m || c < 0 || c >= n)
            return false;

        if (board[r][c] != word[idx])
            return false;

        char ch = board[r][c];

        board[r][c] = '#';

        bool found = dfs(r, c - 1, idx + 1, word, board) ||
                     dfs(r, c + 1, idx + 1, word, board) ||
                     dfs(r - 1, c, idx + 1, word, board) ||
                     dfs(r + 1, c, idx + 1, word, board);

        board[r][c] = ch;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, word, board))
                    return true;
            }
        }

        return false;
    }
};
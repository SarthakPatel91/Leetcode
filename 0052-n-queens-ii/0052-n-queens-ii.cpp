class Solution {
public:
    bool isvalid(int row, int col, int n, vector<string>& board) {
        // upper columns
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int i, int j, int n, vector<string>& board,
               vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isvalid(i, j, n, board)) {
                // place queen
                board[i][j] = 'Q';
                solve(i + 1, j, n, board, ans);

                // backtrack
                board[i][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        solve(0, 0, n, board, ans);

        return ans.size();
    }
};
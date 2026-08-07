class Solution {
public:
    int count = 0;
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

    void solve(int i, int j, int n, vector<string>& board) {
        if (i == n) {
            count = count + 1;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isvalid(i, j, n, board)) {
                // place queen
                board[i][j] = 'Q';
                solve(i + 1, j, n, board);

                // backtrack
                board[i][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        solve(0, 0, n, board);

        return count;
    }
};
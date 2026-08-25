class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;

            word = "";
        }
    };

    int row, col;
    vector<string> ans;

    void insert(TrieNode* root, string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->word = word;
    }

    void dfs(int r, int c,
             vector<vector<char>>& board,
             TrieNode* node) {

        if (r < 0 || r >= row ||
            c < 0 || c >= col ||
            board[r][c] == '#')
            return;

        char ch = board[r][c];

        TrieNode* next = node->child[ch - 'a'];

        if (next == nullptr)
            return;

        // A complete word is found
        if (!next->word.empty()) {
            ans.push_back(next->word);

            // Prevent duplicate answers
            next->word = "";
        }

        // Mark visited
        board[r][c] = '#';

        dfs(r, c - 1, board, next);
        dfs(r, c + 1, board, next);
        dfs(r - 1, c, board, next);
        dfs(r + 1, c, board, next);

        // Backtrack
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        row = board.size();
        col = board[0].size();

        TrieNode* root = new TrieNode();

        // Build Trie
        for (string& word : words) {
            insert(root, word);
        }

        // Start DFS from every cell
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(i, j, board, root);
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans;

    void solve(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (depth % 2 == 1)
                reverse(level.begin(), level.end());

            ans.push_back(level);
            depth++;
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root);

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                curr->val = ans[level][i];

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            level++;
        }

        return root;
    }
};
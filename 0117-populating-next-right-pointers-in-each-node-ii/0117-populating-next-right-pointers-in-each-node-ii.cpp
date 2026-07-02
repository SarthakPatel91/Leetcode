/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<Node*> level;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                level.push_back(node);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            if (level.size() >= 2) {
                for (int i = 1; i < level.size(); i++) {
                    Node* prev = level[i - 1];
                    Node* curr = level[i];
                    prev->next = curr;
                    curr = prev;
                }
                level[level.size() - 1]->next = NULL;

            } else {
                Node* num = level[0];
                num->next = NULL;
            }
        }

        return root;
    }
};
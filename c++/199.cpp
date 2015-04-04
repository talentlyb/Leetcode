/** First time. 4/3/2015
 * 
 * Binary tree level order traversal.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode*> q;
        TreeNode* curr = root;
        TreeNode* next = root;
        TreeNode *node = NULL;
        vector<int> view;
        if (curr) {
            q.push(root);
        }
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                next = node->left;
            }
            if (node->right) {
                q.push(node->right);
                next = node->right;
            }
            if (node == curr) {
                view.push_back(node->val);
                curr = next;
            }
        }
        return view;
    }
};
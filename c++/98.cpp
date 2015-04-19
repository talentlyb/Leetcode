/** First time. 4/18/2015
 * 
 * Binary tree inorder traversal
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
    bool isValidBST(TreeNode *root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        if (inorder.size() < 2) {
            return true;
        }
        
        for (int i = 1; i < inorder.size(); ++i) {
            if (inorder[i-1] >= inorder[i]) {
                return false;
            }
        }
        return true;
    }
    
    void inorderTraversal(TreeNode *root, vector<int> &inorder) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
        return;
    }
};
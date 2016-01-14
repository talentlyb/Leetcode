// First time. 2016/1/14

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int> &num) {
        if (root == NULL) {
            return;
        }
        inOrderTraversal(root->left, num);
        num.push_back(root->val);
        inOrderTraversal(root->right, num);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> num;
        inOrderTraversal(root, num);
        return num[k-1];
    }
};

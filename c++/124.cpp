/** First time. 4/18/2015
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
    int maxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int maxPath = INT_MIN;
        findMax(root, maxPath);
        return maxPath;
    }
    
    int findMax(TreeNode *root, int &maxPath) {
        if (root == NULL) {
            return 0;
        }
        int left = findMax(root->left, maxPath);
        int right = findMax(root->right, maxPath);
        maxPath = max(max(max(max(left + root->val, right + root->val), left + right + root->val), root->val), maxPath);
        return max(max(left + root->val, right + root->val), root->val);
    }
};
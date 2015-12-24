// First time. 2015/12/24

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) {
            return root;
        }
        
        list<TreeNode*> pathToP;
        list<TreeNode*> pathToQ;
        
        // Find the path to node p
        TreeNode *temp = root;
        while (temp != p) {
            pathToP.push_back(temp);
            if (temp->val < p->val) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }
        pathToP.push_back(temp);
        
        // Find the path to node q
        temp = root;
        while (temp != q) {
            pathToQ.push_back(temp);
            if (temp->val < q->val) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }
        pathToQ.push_back(temp);
        
        // Find the LCA
        TreeNode* ret = root;
        while (!pathToP.empty() && !pathToQ.empty()) {
            if (pathToP.front() != pathToQ.front()) {
                return ret;
            }
            else {
                ret = pathToP.front();
                pathToP.pop_front();
                pathToQ.pop_front();
            }
        }
        return ret;
    }
};

// Date: 2016-07-30

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
    bool isBalanced(TreeNode* root) {
        int h;
        return isBalanced(root, h);
    }
    
    bool isBalanced(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }
        int l, r;
        if (!isBalanced(root->left, l) || !isBalanced(root->right, r)) return false;
        height = std::max(l, r) + 1;
        return (l - r <= 1) && (r - l <= 1);
    }
};


// Date: 2016-03-16

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);
        int d = std::min(ld, rd);
        return (d ? d : ld + rd) + 1;
    }
};

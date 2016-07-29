// Date: 2016-07-29

#include <algorithm>

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};


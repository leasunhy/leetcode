// Date: 2016-03-15

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <sstream>
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        std::stringstream ss;
        ss << root->val;
        if (root->left == nullptr && root->right == nullptr)
            res.push_back(ss.str());
        visit(root->left, res, ss.str());
        visit(root->right, res, ss.str());
    }

private:
    void visit(TreeNode* cur, vector<string>& paths, const string& parent) {
        if (cur == nullptr) return;
        std::stringstream ss;
        ss << parent << "->" << cur->val;
        if (cur->left == nullptr && cur->right == nullptr)
            paths.push_back(ss.str());
        visit(cur->left, paths, ss.str());
        visit(cur->right, paths, ss.str());
    }
};


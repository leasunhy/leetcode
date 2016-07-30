// Date: 2016-07-30

#include <utility>
#include <queue>

using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level >= res.size())
                res.resize(level + 1);
            res[level].push_back(cur->val);
            if (cur->left) q.push(make_pair(cur->left, level + 1));
            if (cur->right) q.push(make_pair(cur->right, level + 1));
        }
        return res;
    }
};


// Date: 2016-07-30

#include <stack>
#include <utility>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<TreeNode*, bool>> s;
        s.push(make_pair(root, false));
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            bool visited = s.top().second;
            s.pop();
            if (visited) {
                res.push_back(cur->val);
            } else {
                s.push(make_pair(cur, true));
                if (cur->right) s.push(make_pair(cur->right, false));
                if (cur->left) s.push(make_pair(cur->left, false));
            }
        }
        return res;
    }
};


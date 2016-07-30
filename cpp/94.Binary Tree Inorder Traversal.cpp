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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<TreeNode*, bool>> s;
        add_to_stack(root, s);
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            bool visited = s.top().second;
            s.pop();
            if (!visited)
                add_to_stack(cur, s);
            else
                res.push_back(cur->val);
        }
        return res;
    }
    
    void add_to_stack(TreeNode* root, stack<pair<TreeNode*, bool>>& s) {
        if (!root) return;
        if (root->right) s.push(make_pair(root->right, false));
        s.push(make_pair(root, true));
        if (root->left) s.push(make_pair(root->left, false));
    }
};


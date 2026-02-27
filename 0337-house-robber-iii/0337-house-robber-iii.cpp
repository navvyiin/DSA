#include <algorithm>
using namespace std;

// TreeNode is already defined by the platform

class Solution {
public:
    // returns {rob_this_node, skip_this_node}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int rob = root->val + left.second + right.second;
        int skip = max(left.first, left.second) + max(right.first, right.second);

        return {rob, skip};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
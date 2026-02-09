#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }

        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1, index);
    }

private:
    TreeNode* helper(const vector<int>& preorder,
                     const vector<int>& inorder,
                     int& preIdx,
                     int left,
                     int right,
                     unordered_map<int, int>& index) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = index[rootVal];

        root->left = helper(preorder, inorder, preIdx, left, mid - 1, index);
        root->right = helper(preorder, inorder, preIdx, mid + 1, right, index);

        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }

        int postIdx = postorder.size() - 1;
        return build(inorder, postorder, postIdx, 0, inorder.size() - 1, index);
    }

private:
    TreeNode* build(const vector<int>& inorder,
                    const vector<int>& postorder,
                    int& postIdx,
                    int left,
                    int right,
                    unordered_map<int, int>& index) {
        if (left > right)
            return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = index[rootVal];

        // Build right subtree FIRST
        root->right = build(inorder, postorder, postIdx, mid + 1, right, index);
        root->left  = build(inorder, postorder, postIdx, left, mid - 1, index);

        return root;
    }
};
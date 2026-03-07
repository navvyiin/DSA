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

class Codec {
public:

    // Serialize using preorder traversal
    string serialize(TreeNode* root) {
        string res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode* node, string& res) {
        if (!node) return;
        res += to_string(node->val) + ",";
        preorder(node->left, res);
        preorder(node->right, res);
    }

    // Deserialize using BST property with bounds
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<int> preorder;
        stringstream ss(data);
        string temp;

        while (getline(ss, temp, ',')) {
            if (!temp.empty())
                preorder.push_back(stoi(temp));
        }

        int i = 0;
        return build(preorder, i, INT_MIN, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int& i, int low, int high) {
        if (i >= preorder.size()) return nullptr;

        int val = preorder[i];
        if (val < low || val > high) return nullptr;

        TreeNode* root = new TreeNode(val);
        i++;

        root->left = build(preorder, i, low, val);
        root->right = build(preorder, i, val, high);

        return root;
    }
};
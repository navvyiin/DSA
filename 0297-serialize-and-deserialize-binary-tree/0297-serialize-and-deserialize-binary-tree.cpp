#include <string>
#include <sstream>
using namespace std;

class Codec {
public:
    // Serialize using preorder traversal with '#' as null marker
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Deserialize by reading the preorder stream
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (!node) {
            out << "# ";
            return;
        }
        out << node->val << " ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string token;
        if (!(in >> token))
            return nullptr;

        if (token == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};
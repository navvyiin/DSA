import java.util.*;

class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<>();
        dfs(root, new StringBuilder(), result);
        return result;
    }

    private void dfs(TreeNode node, StringBuilder path, List<String> result) {
        if (node == null) return;

        int lengthBefore = path.length();
        path.append(node.val);

        // If leaf node, store the path
        if (node.left == null && node.right == null) {
            result.add(path.toString());
        } else {
            path.append("->");
            dfs(node.left, path, result);
            dfs(node.right, path, result);
        }

        // Backtrack
        path.setLength(lengthBefore);
    }
}
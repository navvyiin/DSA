import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return null;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            // Swap children
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;

            if (node.left != null) queue.offer(node.left);
            if (node.right != null) queue.offer(node.right);
        }

        return root;
    }
}
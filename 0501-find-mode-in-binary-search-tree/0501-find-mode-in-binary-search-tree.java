import java.util.*;

class Solution {
    int currVal;
    int currCount = 0;
    int maxCount = 0;
    List<Integer> modes = new ArrayList<>();

    public int[] findMode(TreeNode root) {
        inorder(root);
        int[] res = new int[modes.size()];
        for (int i = 0; i < modes.size(); i++) {
            res[i] = modes.get(i);
        }
        return res;
    }

    private void inorder(TreeNode node) {
        if (node == null) return;

        inorder(node.left);

        handleValue(node.val);

        inorder(node.right);
    }

    private void handleValue(int val) {
        if (currCount == 0 || val != currVal) {
            currVal = val;
            currCount = 0;
        }

        currCount++;

        if (currCount > maxCount) {
            maxCount = currCount;
            modes.clear();
            modes.add(val);
        } else if (currCount == maxCount) {
            modes.add(val);
        }
    }
}
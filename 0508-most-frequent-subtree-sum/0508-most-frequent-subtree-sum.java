import java.util.*;

class Solution {
    private Map<Integer, Integer> freq = new HashMap<>();
    private int maxFreq = 0;

    public int[] findFrequentTreeSum(TreeNode root) {
        dfs(root);

        List<Integer> result = new ArrayList<>();
        for (int sum : freq.keySet()) {
            if (freq.get(sum) == maxFreq) {
                result.add(sum);
            }
        }

        int[] ans = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            ans[i] = result.get(i);
        }

        return ans;
    }

    private int dfs(TreeNode node) {
        if (node == null) return 0;

        int left = dfs(node.left);
        int right = dfs(node.right);

        int sum = node.val + left + right;

        freq.put(sum, freq.getOrDefault(sum, 0) + 1);
        maxFreq = Math.max(maxFreq, freq.get(sum));

        return sum;
    }
}
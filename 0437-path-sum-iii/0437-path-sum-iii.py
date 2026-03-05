class Solution:
    def pathSum(self, root, targetSum):
        prefix = {0: 1}
        
        def dfs(node, curr_sum):
            if not node:
                return 0
            
            curr_sum += node.val
            count = prefix.get(curr_sum - targetSum, 0)
            
            prefix[curr_sum] = prefix.get(curr_sum, 0) + 1
            
            count += dfs(node.left, curr_sum)
            count += dfs(node.right, curr_sum)
            
            prefix[curr_sum] -= 1
            
            return count
        
        return dfs(root, 0)
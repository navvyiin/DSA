# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        result = []

        def dfs(node, remaining, path):
            if not node:
                return

            # Include current node
            path.append(node.val)

            # If it's a leaf and sum matches, record the path
            if not node.left and not node.right and node.val == remaining:
                result.append(path.copy())
            else:
                dfs(node.left, remaining - node.val, path)
                dfs(node.right, remaining - node.val, path)

            # Backtrack
            path.pop()

        dfs(root, targetSum, [])
        return result   
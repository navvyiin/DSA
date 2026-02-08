# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        first = second = prev = None
        curr = root

        while curr:
            if curr.left is None:
                # Visit node
                if prev and prev.val > curr.val:
                    if first is None:
                        first = prev
                    second = curr
                prev = curr
                curr = curr.right
            else:
                # Find inorder predecessor
                pred = curr.left
                while pred.right and pred.right != curr:
                    pred = pred.right

                if pred.right is None:
                    # Create thread
                    pred.right = curr
                    curr = curr.left
                else:
                    # Remove thread and visit node
                    pred.right = None
                    if prev and prev.val > curr.val:
                        if first is None:
                            first = prev
                        second = curr
                    prev = curr
                    curr = curr.right

        # Swap the two misplaced nodes
        if first and second:
            first.val, second.val = second.val, first.val
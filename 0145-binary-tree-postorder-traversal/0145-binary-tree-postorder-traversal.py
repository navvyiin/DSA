class Solution:
    def postorderTraversal(self, root):
        result = []
        stack = []
        last_visited = None
        current = root
        
        while stack or current:
            # Go as left as possible
            if current:
                stack.append(current)
                current = current.left
            else:
                peek_node = stack[-1]
                
                # If right child exists and hasn't been processed
                if peek_node.right and last_visited != peek_node.right:
                    current = peek_node.right
                else:
                    result.append(peek_node.val)
                    last_visited = stack.pop()
        
        return result
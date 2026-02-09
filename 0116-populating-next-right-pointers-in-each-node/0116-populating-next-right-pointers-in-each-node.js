var connect = function(root) {
    if (!root) return root;

    let leftmost = root;

    // Traverse level by level
    while (leftmost.left !== null) {
        let curr = leftmost;

        while (curr !== null) {
            // Connect left -> right
            curr.left.next = curr.right;

            // Connect right -> next left (if exists)
            if (curr.next !== null) {
                curr.right.next = curr.next.left;
            }

            curr = curr.next;
        }

        // Move to the next level
        leftmost = leftmost.left;
    }

    return root;
};
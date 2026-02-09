var flatten = function(root) {
    let curr = root;

    while (curr !== null) {
        if (curr.left !== null) {
            // Find rightmost node in left subtree
            let prev = curr.left;
            while (prev.right !== null) {
                prev = prev.right;
            }

            // Rewire connections
            prev.right = curr.right;
            curr.right = curr.left;
            curr.left = null;
        }

        // Move to next node
        curr = curr.right;
    }
};
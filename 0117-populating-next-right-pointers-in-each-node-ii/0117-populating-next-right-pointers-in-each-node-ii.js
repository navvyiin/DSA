var connect = function(root) {
    if (!root) return null;

    let curr = root;

    while (curr !== null) {
        // Dummy node for the next level
        let dummy = new _Node(0);
        let tail = dummy;

        // Traverse current level using next pointers
        while (curr !== null) {
            if (curr.left !== null) {
                tail.next = curr.left;
                tail = tail.next;
            }
            if (curr.right !== null) {
                tail.next = curr.right;
                tail = tail.next;
            }
            curr = curr.next;
        }

        // Move to the first node of the next level
        curr = dummy.next;
    }

    return root;
};
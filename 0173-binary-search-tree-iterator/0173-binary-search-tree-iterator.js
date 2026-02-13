var BSTIterator = function(root) {
    this.stack = [];
    this._pushLeft(root);
};

// Helper function to push all left descendants
BSTIterator.prototype._pushLeft = function(node) {
    while (node !== null) {
        this.stack.push(node);
        node = node.left;
    }
};

BSTIterator.prototype.next = function() {
    let node = this.stack.pop();

    if (node.right !== null) {
        this._pushLeft(node.right);
    }

    return node.val;
};

BSTIterator.prototype.hasNext = function() {
    return this.stack.length > 0;
};
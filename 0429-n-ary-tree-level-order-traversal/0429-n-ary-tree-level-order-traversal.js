var levelOrder = function(root) {
    if (!root) return [];
    
    let result = [];
    let queue = [root];

    while (queue.length) {
        let size = queue.length;
        let level = [];

        for (let i = 0; i < size; i++) {
            let node = queue.shift();
            level.push(node.val);

            if (node.children) {
                for (let child of node.children) {
                    queue.push(child);
                }
            }
        }

        result.push(level);
    }

    return result;
};
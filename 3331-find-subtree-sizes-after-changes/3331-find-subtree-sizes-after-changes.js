var findSubtreeSizes = function(parent, s) {
    const n = parent.length;
    const children = Array.from({ length: n }, () => []);

    for (let i = 1; i < n; i++) {
        children[parent[i]].push(i);
    }

    const last = Array(26).fill(-1);
    const newParent = Array(n).fill(-1);
    const order = [];

    // Iterative DFS to avoid recursion stack overflow.
    const stack = [[0, 0, -1]];

    while (stack.length > 0) {
        const [u, state, previous] = stack.pop();
        const c = s.charCodeAt(u) - 97;

        if (state === 1) {
            last[c] = previous;
            continue;
        }

        const old = last[c];

        // Find the nearest matching ancestor in the original tree.
        newParent[u] = old !== -1 ? old : parent[u];

        last[c] = u;
        order.push(u);

        // Restore the previous character occurrence after visiting
        // this node's entire subtree.
        stack.push([u, 1, old]);

        for (let i = children[u].length - 1; i >= 0; i--) {
            stack.push([children[u][i], 0, -1]);
        }
    }

    // Calculate subtree sizes in the modified tree.
    const answer = Array(n).fill(1);

    for (let i = order.length - 1; i >= 0; i--) {
        const u = order[i];

        if (newParent[u] !== -1) {
            answer[newParent[u]] += answer[u];
        }
    }

    return answer;
};
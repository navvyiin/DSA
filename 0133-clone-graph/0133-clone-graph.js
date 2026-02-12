/**
 * // Definition for a _Node.
 * function _Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {_Node} node
 * @return {_Node}
 */
var cloneGraph = function(node) {
    if (!node) return null;

    const visited = new Map();

    function dfs(current) {
        // If already cloned, return the clone
        if (visited.has(current)) {
            return visited.get(current);
        }

        // Create clone
        const clone = new _Node(current.val);
        visited.set(current, clone);

        // Clone neighbors recursively
        for (let neighbor of current.neighbors) {
            clone.neighbors.push(dfs(neighbor));
        }

        return clone;
    }

    return dfs(node);
};
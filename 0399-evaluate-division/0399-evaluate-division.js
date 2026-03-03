var calcEquation = function(equations, values, queries) {
    const graph = new Map();
    
    // Build graph
    for (let i = 0; i < equations.length; i++) {
        const [a, b] = equations[i];
        const value = values[i];
        
        if (!graph.has(a)) graph.set(a, []);
        if (!graph.has(b)) graph.set(b, []);
        
        graph.get(a).push([b, value]);
        graph.get(b).push([a, 1 / value]);
    }
    
    const results = [];
    
    for (const [start, end] of queries) {
        if (!graph.has(start) || !graph.has(end)) {
            results.push(-1.0);
        } else if (start === end) {
            results.push(1.0);
        } else {
            results.push(bfs(start, end, graph));
        }
    }
    
    return results;
};

function bfs(start, end, graph) {
    const queue = [[start, 1.0]];
    const visited = new Set();
    visited.add(start);
    
    while (queue.length > 0) {
        const [node, product] = queue.shift();
        
        if (node === end) {
            return product;
        }
        
        for (const [neighbor, value] of graph.get(node)) {
            if (!visited.has(neighbor)) {
                visited.add(neighbor);
                queue.push([neighbor, product * value]);
            }
        }
    }
    
    return -1.0;
}
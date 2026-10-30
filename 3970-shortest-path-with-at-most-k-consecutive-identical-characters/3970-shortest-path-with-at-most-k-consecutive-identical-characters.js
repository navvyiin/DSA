var shortestPath = function(n, edges, labels, k) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        adj[u].push([v, w]);
    }
    const stride = k + 1;
    const dist = new Float64Array(n * stride);
    dist.fill(Infinity);
    const heap = [];
    function push(d, state) {
        let i = heap.length;
        heap.push([d, state]);
        while (i > 0) {
            const p = (i - 1) >> 1;
            if (heap[p][0] <= d) break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = [d, state];
    }
    function pop() {
        const result = heap[0];
        const last = heap.pop();
        if (heap.length > 0) {
            let i = 0;
            while (true) {
                let child = i * 2 + 1;
                if (child >= heap.length) break;
                if (child + 1 < heap.length &&
                    heap[child + 1][0] < heap[child][0]) {
                    child++;
                }
                if (heap[child][0] >= last[0]) break;
                heap[i] = heap[child];
                i = child;
            }
            heap[i] = last;
        }
        return result;
    }
    const startState = 1;
    dist[startState] = 0;
    push(0, startState);
    while (heap.length > 0) {
        const [d, state] = pop();
        if (d !== dist[state]) continue;
        const u = Math.floor(state / stride);
        const count = state % stride;
        if (u === n - 1) return d;
        for (const [v, w] of adj[u]) {
            const nextCount =
                labels[u] === labels[v] ? count + 1 : 1;
            if (nextCount > k) continue;
            const nextState = v * stride + nextCount;
            const newDist = d + w;
            if (newDist < dist[nextState]) {
                dist[nextState] = newDist;
                push(newDist, nextState);
            }
        }
    }
    return -1;
};
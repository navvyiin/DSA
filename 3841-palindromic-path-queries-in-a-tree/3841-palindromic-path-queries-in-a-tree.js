var palindromePath = function(n, edges, s, queries) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const LOG = Math.ceil(Math.log2(n)) + 1;
    const parent = new Int32Array(n);
    const depth = new Int32Array(n);
    const tin = new Int32Array(n);
    const tout = new Int32Array(n);
    const prefix = new Int32Array(n);
    const up = Array.from({ length: LOG }, () => new Int32Array(n));
    const chars = s.split("");
    let timer = 0;
    const stack = [[0, 0, false]];
    while (stack.length) {
        const [u, p, exiting] = stack.pop();
        if (exiting) {
            tout[u] = timer - 1;
            continue;
        }
        parent[u] = p;
        up[0][u] = p;
        tin[u] = timer++;
        const bit = 1 << (chars[u].charCodeAt(0) - 97);
        prefix[u] = (u === 0 ? 0 : prefix[p]) ^ bit;
        stack.push([u, p, true]);
        for (let i = adj[u].length - 1; i >= 0; i--) {
            const v = adj[u][i];
            if (v !== p) {
                depth[v] = depth[u] + 1;
                stack.push([v, u, false]);
            }
        }
    }
    for (let j = 1; j < LOG; j++) {
        for (let u = 0; u < n; u++) {
            up[j][u] = up[j - 1][up[j - 1][u]];
        }
    }
    const lca = (a, b) => {
        if (depth[a] < depth[b]) {
            [a, b] = [b, a];
        }
        let diff = depth[a] - depth[b];
        for (let j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                a = up[j][a];
            }
        }
        if (a === b) return a;
        for (let j = LOG - 1; j >= 0; j--) {
            if (up[j][a] !== up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }
        return parent[a];
    };
    const bit = new Int32Array(n + 2);
    const updateBit = (i, delta) => {
        while (i < bit.length) {
            bit[i] ^= delta;
            i += i & -i;
        }
    };
    const queryBit = (i) => {
        let mask = 0;
        while (i > 0) {
            mask ^= bit[i];
            i -= i & -i;
        }
        return mask;
    };
    const rangeXor = (left, right, delta) => {
        updateBit(left + 1, delta);
        updateBit(right + 2, delta);
    };
    const currentPrefix = (u) => {
        return prefix[u] ^ queryBit(tin[u] + 1);
    };
    const answer = [];
    for (const q of queries) {
        const parts = q.split(" ");
        const type = parts[0];
        const u = Number(parts[1]);
        if (type === "update") {
            const c = parts[2];
            const oldBit = 1 << (chars[u].charCodeAt(0) - 97);
            const newBit = 1 << (c.charCodeAt(0) - 97);
            const delta = oldBit ^ newBit;
            if (delta !== 0) {
                rangeXor(tin[u], tout[u], delta);
                chars[u] = c;
            }
        } else {
            const v = Number(parts[2]);
            const ancestor = lca(u, v);
            const mask =
                currentPrefix(u) ^
                currentPrefix(v) ^
                (1 << (chars[ancestor].charCodeAt(0) - 97));
            answer.push((mask & (mask - 1)) === 0);
        }
    }
    return answer;
};
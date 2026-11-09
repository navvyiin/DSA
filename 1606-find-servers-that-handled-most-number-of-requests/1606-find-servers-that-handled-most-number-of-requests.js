var busiestServers = function(k, arrival, load) {
    const n = arrival.length;
    const count = new Array(k).fill(0);
    class MinHeap {
        constructor() {
            this.heap = [];
        }
        push(value) {
            const h = this.heap;
            h.push(value);
            let i = h.length - 1;
            while (i > 0) {
                const p = (i - 1) >> 1;
                if (h[p][0] <= value[0]) break;
                h[i] = h[p];
                i = p;
            }
            h[i] = value;
        }
        pop() {
            const h = this.heap;
            const result = h[0];
            const last = h.pop();
            if (h.length > 0) {
                let i = 0;
                while (true) {
                    let child = i * 2 + 1;
                    if (child >= h.length) break;
                    if (
                        child + 1 < h.length &&
                        h[child + 1][0] < h[child][0]
                    ) {
                        child++;
                    }
                    if (h[child][0] >= last[0]) break;
                    h[i] = h[child];
                    i = child;
                }
                h[i] = last;
            }
            return result;
        }
        peek() {
            return this.heap[0];
        }
        size() {
            return this.heap.length;
        }
    }
    const seg = new Int32Array(4 * k);
    function build(node, l, r) {
        if (l === r) {
            seg[node] = 1;
            return;
        }
        const mid = (l + r) >> 1;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
    function update(node, l, r, pos, value) {
        if (l === r) {
            seg[node] = value;
            return;
        }
        const mid = (l + r) >> 1;
        if (pos <= mid) {
            update(node * 2, l, mid, pos, value);
        } else {
            update(node * 2 + 1, mid + 1, r, pos, value);
        }
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
    function findFirst(node, l, r, start) {
        if (r < start || seg[node] === 0) {
            return -1;
        }
        if (l === r) {
            return l;
        }
        const mid = (l + r) >> 1;
        let result = findFirst(node * 2, l, mid, start);
        if (result !== -1) {
            return result;
        }
        return findFirst(node * 2 + 1, mid + 1, r, start);
    }
    build(1, 0, k - 1);
    const busy = new MinHeap();
    for (let i = 0; i < n; i++) {
        const time = arrival[i];
        while (busy.size() > 0 && busy.peek()[0] <= time) {
            const [finish, server] = busy.pop();
            update(1, 0, k - 1, server, 1);
        }
        if (seg[1] === 0) {
            continue;
        }
        const start = i % k;
        let server = findFirst(1, 0, k - 1, start);
        if (server === -1) {
            server = findFirst(1, 0, k - 1, 0);
        }
        count[server]++;
        update(1, 0, k - 1, server, 0);
        busy.push([
            time + load[i],
            server
        ]);
    }
    const maxRequests = Math.max(...count);
    const result = [];
    for (let i = 0; i < k; i++) {
        if (count[i] === maxRequests) {
            result.push(i);
        }
    }
    return result;
};
var assignTasks = function(servers, tasks) {
    const n = servers.length;
    const m = tasks.length;

    class MinHeap {
        constructor(compare) {
            this.heap = [];
            this.compare = compare;
        }

        push(val) {
            const heap = this.heap;
            heap.push(val);

            let i = heap.length - 1;

            while (i > 0) {
                const p = Math.floor((i - 1) / 2);

                if (this.compare(heap[p], val) <= 0) break;

                heap[i] = heap[p];
                i = p;
            }

            heap[i] = val;
        }

        pop() {
            const heap = this.heap;
            const result = heap[0];
            const last = heap.pop();

            if (heap.length > 0) {
                let i = 0;

                while (true) {
                    let child = 2 * i + 1;

                    if (child >= heap.length) break;

                    if (
                        child + 1 < heap.length &&
                        this.compare(heap[child + 1], heap[child]) < 0
                    ) {
                        child++;
                    }

                    if (this.compare(last, heap[child]) <= 0) break;

                    heap[i] = heap[child];
                    i = child;
                }

                heap[i] = last;
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

    const free = new MinHeap((a, b) =>
        a[0] - b[0] || a[1] - b[1]
    );

    const busy = new MinHeap((a, b) =>
        a[0] - b[0] || a[1] - b[1] || a[2] - b[2]
    );

    for (let i = 0; i < n; i++) {
        free.push([servers[i], i]);
    }

    const ans = new Array(m);
    let time = 0;

    for (let i = 0; i < m; i++) {
        time = Math.max(time, i);

        while (busy.size() > 0 && busy.peek()[0] <= time) {
            const [finish, weight, index] = busy.pop();
            free.push([weight, index]);
        }

        if (free.size() === 0) {
            time = busy.peek()[0];

            while (busy.size() > 0 && busy.peek()[0] <= time) {
                const [finish, weight, index] = busy.pop();
                free.push([weight, index]);
            }
        }

        const [weight, index] = free.pop();

        ans[i] = index;

        busy.push([
            time + tasks[i],
            weight,
            index
        ]);
    }

    return ans;
};
var minOperations = function(nums, x, k) {
    const n = nums.length;
    const values = [...new Set(nums)].sort((a, b) => a - b);
    const m = values.length;
    const rank = new Map();
    for (let i = 0; i < m; i++) {
        rank.set(values[i], i + 1);
    }
    const bitCount = new Int32Array(m + 1);
    const bitSum = new Float64Array(m + 1);
    function update(pos, dc, ds) {
        while (pos <= m) {
            bitCount[pos] += dc;
            bitSum[pos] += ds;
            pos += pos & -pos;
        }
    }
    function queryCount(pos) {
        let res = 0;
        while (pos > 0) {
            res += bitCount[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    function querySum(pos) {
        let res = 0;
        while (pos > 0) {
            res += bitSum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    let maxBit = 1;
    while (maxBit * 2 <= m) {
        maxBit *= 2;
    }
    function kth(kthValue) {
        let idx = 0;
        let count = 0;
        for (let step = maxBit; step > 0; step >>= 1) {
            const next = idx + step;
            if (next <= m && count + bitCount[next] < kthValue) {
                idx = next;
                count += bitCount[next];
            }
        }
        return idx + 1;
    }
    const windowCount = n - x + 1;
    const costs = new Float64Array(windowCount);
    let totalSum = 0;
    for (let i = 0; i < x; i++) {
        update(rank.get(nums[i]), 1, nums[i]);
        totalSum += nums[i];
    }
    for (let start = 0; start < windowCount; start++) {
        const medianPos = kth(Math.ceil(x / 2));
        const median = values[medianPos - 1];
        const leftCount = queryCount(medianPos);
        const leftSum = querySum(medianPos);
        const rightCount = x - leftCount;
        const rightSum = totalSum - leftSum;
        costs[start] =
            median * leftCount - leftSum +
            rightSum - median * rightCount;
        if (start + 1 < windowCount) {
            const outgoing = nums[start];
            const incoming = nums[start + x];
            update(rank.get(outgoing), -1, -outgoing);
            update(rank.get(incoming), 1, incoming);
            totalSum += incoming - outgoing;
        }
    }
    let prev = new Float64Array(n + 1);
    for (let j = 1; j <= k; j++) {
        const curr = new Float64Array(n + 1);
        curr.fill(Infinity);
        for (let i = j * x; i <= n; i++) {
            curr[i] = curr[i - 1];
            const candidate = prev[i - x] + costs[i - x];
            curr[i] = Math.min(curr[i], candidate);
        }
        prev = curr;
    }
    return prev[n];
};
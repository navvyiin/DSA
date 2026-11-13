/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countNonDecreasingSubarrays = function(nums, k) {
    const n = nums.length;
    const next = new Int32Array(n);
    const stack = [];
    for (let i = n - 1; i >= 0; i--) {
        while (stack.length && nums[stack[stack.length - 1]] <= nums[i]) {
            stack.pop();
        }
        next[i] = stack.length ? stack[stack.length - 1] : n;
        stack.push(i);
    }
    const prefix = new Float64Array(n + 1);
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    const LOG = Math.ceil(Math.log2(n)) + 1;
    const jump = new Array(LOG);
    const sum = new Array(LOG)
    jump[0] = next;
    sum[0] = new Float64Array(n);
    for (let i = 0; i < n; i++) {
        sum[0][i] = nums[i] * (next[i] - i);
    }
    for (let p = 1; p < LOG; p++) {
        jump[p] = new Int32Array(n);
        sum[p] = new Float64Array(n);
        for (let i = 0; i < n; i++) {
            const mid = jump[p - 1][i];
            if (mid === n) {
                jump[p][i] = n;
                sum[p][i] = sum[p - 1][i];
            } else {
                jump[p][i] = jump[p - 1][mid];
                sum[p][i] = sum[p - 1][i] + sum[p - 1][mid];
            }
        }
    }
    function getMaxSum(l, r) {
        let pos = l;
        let result = 0;
        for (let p = LOG - 1; p >= 0; p--) {
            const nxt = jump[p][pos];
            if (nxt <= r + 1) {
                result += sum[p][pos];
                pos = nxt;
                if (pos === n) break;
            }
        }
        if (pos <= r) {
            result += nums[pos] * (r - pos + 1);
        }
        return result;
    }
    function getCost(l, r) {
        return getMaxSum(l, r) - (prefix[r + 1] - prefix[l]);
    }
    let left = 0;
    let answer = 0;
    for (let right = 0; right < n; right++) {
        while (getCost(left, right) > k) {
            left++;
        }
        answer += right - left + 1;
    }
    return answer;
};
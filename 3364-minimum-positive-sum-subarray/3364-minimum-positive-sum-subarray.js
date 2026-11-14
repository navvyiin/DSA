/**
 * @param {number[]} nums
 * @param {number} l
 * @param {number} r
 * @return {number}
 */
var minimumSumSubarray = function(nums, l, r) {
    const n = nums.length;
    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    let ans = Infinity;
    for (let i = 0; i < n; i++) {
        for (let len = l; len <= r && i + len <= n; len++) {
            const sum = prefix[i + len] - prefix[i];
            if (sum > 0) {
                ans = Math.min(ans, sum);
            }
        }
    }
    return ans === Infinity ? -1 : ans;
};
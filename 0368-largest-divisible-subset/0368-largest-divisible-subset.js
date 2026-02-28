var largestDivisibleSubset = function(nums) {
    if (nums.length === 0) return [];

    nums.sort((a, b) => a - b);

    const n = nums.length;
    const dp = new Array(n).fill(1);     // dp[i] = length of largest subset ending at i
    const prev = new Array(n).fill(-1);  // prev index for reconstruction

    let maxLen = 1;
    let maxIdx = 0;

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[i] % nums[j] === 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIdx = i;
        }
    }

    const result = [];
    let curr = maxIdx;
    while (curr !== -1) {
        result.push(nums[curr]);
        curr = prev[curr];
    }

    return result.reverse();
};
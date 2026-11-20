/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSelectedElements = function(nums) {
    nums.sort((a, b) => a - b);
    let dp = new Map();
    let ans = 0;
    for (const x of nums) {
        const extendWithoutIncrement = (dp.get(x) || 0) + 1;
        const extendWithIncrement = (dp.get(x + 1) || 0) +1;
        dp.set(x + 2, Math.max(dp.get(x +2) || 0, extendWithIncrement));
        dp.set(x + 1, Math.max(dp.get (x + 1) || 0, extendWithoutIncrement));
        ans = Math.max(ans, dp.get(x + 1), dp.get(x + 2));
    }
    return ans;
};
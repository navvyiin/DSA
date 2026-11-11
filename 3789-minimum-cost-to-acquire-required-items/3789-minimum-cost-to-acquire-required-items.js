/**
 * @param {number} cost1
 * @param {number} cost2
 * @param {number} costBoth
 * @param {number} need1
 * @param {number} need2
 * @return {number}
 */
var minimumCost = function(cost1, cost2, costBoth, need1, need2) {
    const common = Math.min(need1, need2);
    let ans = common * Math.min(costBoth, cost1 + cost2);
    ans += (need1 - common) * Math.min(cost1, costBoth);
    ans += (need2 - common) * Math.min(cost2, costBoth);
    return ans;
};
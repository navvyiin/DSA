var climbStairs = function(n, costs) {
    let dp1 = 0;
    let dp2 = Infinity;
    let dp3 = Infinity;

    for (let i = 1; i <= n; i++) {
        let best = dp1 + 1;

        if (i >= 2) {
            best = Math.min(best, dp2 + 4);
        }

        if (i >= 3) {
            best = Math.min(best, dp3 + 9);
        }

        const curr = costs[i - 1] + best;

        dp3 = dp2;
        dp2 = dp1;
        dp1 = curr;
    }

    return dp1;
};
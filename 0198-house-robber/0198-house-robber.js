var rob = function(nums) {
    let prev2 = 0; // dp[i-2]
    let prev1 = 0; // dp[i-1]

    for (let money of nums) {
        let current = Math.max(prev1, prev2 + money);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
};
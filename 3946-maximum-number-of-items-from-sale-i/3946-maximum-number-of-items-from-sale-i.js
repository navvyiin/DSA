var maximumSaleItems = function(items, budget) {
    const n = items.length;
    const dp = new Array(budget + 1).fill(0);
    let minPrice = Infinity;
    for (let i = 0; i < n; i++) {
        const [factor, price] = items[i];
        minPrice = Math.min(minPrice, price);
        let count = 0;
        for (let j = 0; j < n; j++) {
            if (items[j][0] % factor === 0) {
                count++;
            }
        }
        for (let j = budget; j >= price; j--) {
            dp[j] = Math.max(dp[j], dp[j - price] + count);
        }
    }
    let answer = 0;
    for (let i = 0; i <= budget; i++) {
        const extraCopies = Math.floor((budget - i) / minPrice);
        answer = Math.max(answer, dp[i] + extraCopies);
    }
    return answer;
};
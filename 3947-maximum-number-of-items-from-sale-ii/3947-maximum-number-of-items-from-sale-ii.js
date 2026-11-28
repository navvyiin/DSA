var maximumSaleItems = function(items, budget) {
    const n = items.length;
    const freq = new Array(n + 1).fill(0);
    let minPrice = Infinity;
    let maxFactor = 0;
    for (const [factor, price] of items) {
        freq[factor]++;
        minPrice = Math.min(minPrice, price);
        maxFactor = Math.max(maxFactor, factor);
    }
    const divisible = freq.slice();
    for (let f = 1; f <= maxFactor; f++) {
        for (let multiple = 2 * f; multiple <= maxFactor; multiple += f) {
            divisible[f] += freq[multiple];
        }
    }
    const opportunities = [];
    for (const [factor, price] of items) {
        const gain = divisible[factor] - 1;
        if (gain > 0 && price <= 2 * minPrice) {
            opportunities.push([price, gain]);
        }
    }
    opportunities.sort((a, b) => a[0] - b[0]);
    let answer = 0;
    for (const [price, count] of opportunities) {
        const buy = Math.min(count, Math.floor(budget / price));
        answer += buy * 2;
        budget -= buy * price;
        if (buy < count) break;
    }
    answer += Math.floor(budget / minPrice);
    return answer;
};
var maxLength = function(nums) {
    const n = nums.length;
    let ans = 0;
    const gcd = (a, b) => {
        while (b !== 0n) {
            const temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    };
    for (let i = 0; i < n; i++) {
        let product = 1n;
        let currentGcd = 0n;
        let currentLcm = 1n;
        for (let j = i; j < n; j++) {
            const x = BigInt(nums[j]);
            product *= x;
            currentGcd = gcd(currentGcd, x);
            currentLcm = (currentLcm / gcd(currentLcm, x)) * x;
            if (product === currentGcd * currentLcm) {
                ans = Math.max(ans, j - i + 1);
            }
        }
    }
    return ans;
};
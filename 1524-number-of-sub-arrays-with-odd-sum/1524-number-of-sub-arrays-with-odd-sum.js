/**
 * @param {number[]} arr
 * @return {number}
 */
var numOfSubarrays = function(arr) {
    const MOD = 1_000_000_007;
    let even = 1;
    let odd = 0;
    let parity = 0;
    let ans = 0;
    for (const num of arr) {
        parity ^= num & 1;

        if (parity === 1) {
            ans = (ans + even) % MOD;
            odd++;
        } else {
            ans = (ans + odd) % MOD;
            even++;
        }
    }
    return ans;
};
var canIWin = function(maxChoosableInteger, desiredTotal) {
    if (desiredTotal <= 0) return true;

    const sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
    if (sum < desiredTotal) return false;

    const memo = new Map();

    function dfs(usedMask, remaining) {
        if (memo.has(usedMask)) return memo.get(usedMask);

        for (let i = 1; i <= maxChoosableInteger; i++) {
            const bit = 1 << (i - 1);
            if ((usedMask & bit) === 0) {
                if (i >= remaining || !dfs(usedMask | bit, remaining - i)) {
                    memo.set(usedMask, true);
                    return true;
                }
            }
        }

        memo.set(usedMask, false);
        return false;
    }

    return dfs(0, desiredTotal);
};
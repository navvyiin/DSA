var countArrangement = function(n) {
    let used = new Array(n + 1).fill(false);
    let count = 0;

    function backtrack(pos) {
        if (pos > n) {
            count++;
            return;
        }

        for (let num = 1; num <= n; num++) {
            if (!used[num] && (num % pos === 0 || pos % num === 0)) {
                used[num] = true;
                backtrack(pos + 1);
                used[num] = false;
            }
        }
    }

    backtrack(1);
    return count;
};
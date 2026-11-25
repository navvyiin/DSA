var smallestUniqueSubarray = function(nums) {
    const n = nums.length;
    let sa = Array.from({ length: n }, (_, i) => i);
    let rank = nums.slice();
    let nextRank = new Array(n);
    for (let len = 1; len < n; len *= 2) {
        sa.sort((a, b) => {
            if (rank[a] !== rank[b]) {
                return rank[a] - rank[b];
            }
            const ra = a + len < n ? rank[a + len] : -1;
            const rb = b + len < n ? rank[b + len] : -1;
            return ra - rb;
        });
        nextRank[sa[0]] = 0;
        for (let i = 1; i < n; i++) {
            const a = sa[i - 1];
            const b = sa[i];
            const a2 = a + len < n ? rank[a + len] : -1;
            const b2 = b + len < n ? rank[b + len] : -1;
            nextRank[b] = nextRank[a] +
                (rank[a] !== rank[b] || a2 !== b2 ? 1 : 0);
        }
        [rank, nextRank] = [nextRank, rank];
        if (rank[sa[n - 1]] === n - 1) break;
    }
    const position = new Array(n);
    for (let i = 0; i < n; i++) {
        position[sa[i]] = i;
    }
    const lcp = new Array(n).fill(0);
    let h = 0;
    for (let i = 0; i < n; i++) {
        const r = position[i];
        if (r === 0) {
            h = 0;
            continue;
        }
        const j = sa[r - 1];
        while (
            i + h < n &&
            j + h < n &&
            nums[i + h] === nums[j + h]
        ) {
            h++;
        }
        lcp[r] = h;
        if (h > 0) h--;
    }
    let ans = n;
    for (let i = 0; i < n; i++) {
        const common = Math.max(
            lcp[i],
            i + 1 < n ? lcp[i + 1] : 0
        );
        const uniqueLength = common + 1;
        const remainingLength = n - sa[i];
        if (uniqueLength <= remainingLength) {
            ans = Math.min(ans, uniqueLength);
        }
    }
    return ans;
};
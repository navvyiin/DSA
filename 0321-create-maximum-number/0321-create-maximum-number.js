var maxNumber = function(nums1, nums2, k) {
    // Pick max subsequence of length t from nums
    function maxSubsequence(nums, t) {
        const stack = [];
        let drop = nums.length - t;

        for (const num of nums) {
            while (drop > 0 && stack.length && stack[stack.length - 1] < num) {
                stack.pop();
                drop--;
            }
            stack.push(num);
        }
        return stack.slice(0, t);
    }

    // Compare arrays a[i:] and b[j:]
    function greater(a, i, b, j) {
        while (i < a.length && j < b.length && a[i] === b[j]) {
            i++;
            j++;
        }
        return j === b.length || (i < a.length && a[i] > b[j]);
    }

    // Merge two subsequences into the largest possible sequence
    function merge(a, b) {
        const res = [];
        let i = 0, j = 0;

        while (i < a.length || j < b.length) {
            if (greater(a, i, b, j)) {
                res.push(a[i++]);
            } else {
                res.push(b[j++]);
            }
        }
        return res;
    }

    let best = [];

    const start = Math.max(0, k - nums2.length);
    const end = Math.min(k, nums1.length);

    for (let i = start; i <= end; i++) {
        const part1 = maxSubsequence(nums1, i);
        const part2 = maxSubsequence(nums2, k - i);
        const candidate = merge(part1, part2);

        if (greater(candidate, 0, best, 0)) {
            best = candidate;
        }
    }

    return best;
};
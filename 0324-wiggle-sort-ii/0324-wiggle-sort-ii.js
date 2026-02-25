var wiggleSort = function(nums) {
    const n = nums.length;

    // Quickselect to find median
    function nthElement(arr, k) {
        let left = 0, right = arr.length - 1;
        while (true) {
            const pivot = arr[Math.floor(Math.random() * (right - left + 1)) + left];
            let i = left, j = right, t = left;
            while (t <= j) {
                if (arr[t] < pivot) {
                    [arr[i], arr[t]] = [arr[t], arr[i]];
                    i++; t++;
                } else if (arr[t] > pivot) {
                    [arr[t], arr[j]] = [arr[j], arr[t]];
                    j--;
                } else {
                    t++;
                }
            }
            if (k < i) right = i - 1;
            else if (k > j) left = j + 1;
            else return arr[k];
        }
    }

    const median = nthElement(nums.slice(), Math.floor((n - 1) / 2));

    // Virtual index mapping
    const idx = i => (1 + 2 * i) % (n | 1);

    let i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (nums[idx(j)] > median) {
            [nums[idx(i)], nums[idx(j)]] = [nums[idx(j)], nums[idx(i)]];
            i++; j++;
        } else if (nums[idx(j)] < median) {
            [nums[idx(j)], nums[idx(k)]] = [nums[idx(k)], nums[idx(j)]];
            k--;
        } else {
            j++;
        }
    }
};
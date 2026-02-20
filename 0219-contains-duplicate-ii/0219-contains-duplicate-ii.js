var containsNearbyDuplicate = function(nums, k) {
    const lastIndex = new Map();

    for (let i = 0; i < nums.length; i++) {
        if (lastIndex.has(nums[i])) {
            if (i - lastIndex.get(nums[i]) <= k) {
                return true;
            }
        }
        lastIndex.set(nums[i], i);
    }

    return false;
};
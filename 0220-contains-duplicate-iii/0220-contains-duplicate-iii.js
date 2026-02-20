var containsNearbyAlmostDuplicate = function(nums, indexDiff, valueDiff) {
    if (valueDiff < 0) return false;

    const bucketSize = valueDiff + 1;
    const buckets = new Map();

    const getBucketId = (num) => {
        return Math.floor(num / bucketSize);
    };

    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        const bucketId = getBucketId(num);

        // Same bucket
        if (buckets.has(bucketId)) {
            return true;
        }

        // Neighbouring buckets
        if (
            (buckets.has(bucketId - 1) && Math.abs(num - buckets.get(bucketId - 1)) <= valueDiff) ||
            (buckets.has(bucketId + 1) && Math.abs(num - buckets.get(bucketId + 1)) <= valueDiff)
        ) {
            return true;
        }

        buckets.set(bucketId, num);

        // Remove element outside the sliding window
        if (i >= indexDiff) {
            const oldBucketId = getBucketId(nums[i - indexDiff]);
            buckets.delete(oldBucketId);
        }
    }

    return false;
};
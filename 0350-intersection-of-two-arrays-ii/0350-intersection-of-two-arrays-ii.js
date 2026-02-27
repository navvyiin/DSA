var intersect = function(nums1, nums2) {
    // Ensure nums1 is the smaller array for better space usage
    if (nums1.length > nums2.length) {
        return intersect(nums2, nums1);
    }

    const count = new Map();
    const result = [];

    // Count frequencies in nums1
    for (const num of nums1) {
        count.set(num, (count.get(num) || 0) + 1);
    }

    // Build intersection using nums2
    for (const num of nums2) {
        if (count.has(num) && count.get(num) > 0) {
            result.push(num);
            count.set(num, count.get(num) - 1);
        }
    }

    return result;
};
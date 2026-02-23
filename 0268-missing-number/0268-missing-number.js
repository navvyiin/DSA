var missingNumber = function(nums) {
    let xor = nums.length;

    for (let i = 0; i < nums.length; i++) {
        xor ^= i;
        xor ^= nums[i];
    }

    return xor;
};
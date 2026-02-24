var moveZeroes = function(nums) {
    let k = 0; // index for next non-zero position

    // First pass: move non-zero elements forward
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Second pass: fill remaining positions with zeros
    for (let i = k; i < nums.length; i++) {
        nums[i] = 0;
    }
};
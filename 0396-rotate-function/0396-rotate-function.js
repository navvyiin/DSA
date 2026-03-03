var maxRotateFunction = function(nums) {
    const n = nums.length;
    
    let totalSum = 0;
    let F = 0;
    
    for (let i = 0; i < n; i++) {
        totalSum += nums[i];
        F += i * nums[i];
    }
    
    let maxValue = F;
    
    for (let k = 1; k < n; k++) {
        F = F + totalSum - n * nums[n - k];
        maxValue = Math.max(maxValue, F);
    }
    
    return maxValue;
};
var Solution = function(nums) {
    this.nums = nums;
};

/**
 * @param {number} target
 * @return {number}
 */
Solution.prototype.pick = function(target) {
    let count = 0;
    let chosenIndex = -1;
    
    for (let i = 0; i < this.nums.length; i++) {
        if (this.nums[i] === target) {
            count++;
            // Reservoir sampling: replace with probability 1/count
            if (Math.floor(Math.random() * count) === 0) {
                chosenIndex = i;
            }
        }
    }
    
    return chosenIndex;
};
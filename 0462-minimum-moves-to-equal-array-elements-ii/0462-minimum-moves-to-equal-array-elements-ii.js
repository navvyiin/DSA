var minMoves2 = function(nums) {
    nums.sort((a, b) => a - b);
    const median = nums[Math.floor(nums.length / 2)];
    
    let moves = 0;
    for (let num of nums) {
        moves += Math.abs(num - median);
    }
    
    return moves;
};
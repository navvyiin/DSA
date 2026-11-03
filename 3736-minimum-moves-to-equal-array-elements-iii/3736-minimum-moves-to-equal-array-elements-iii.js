var minMoves = function(nums) {
    const max = Math.max(...nums);
    let moves = 0;
    for (const num of nums) {
        moves += max - num;
    }
    return moves;
};
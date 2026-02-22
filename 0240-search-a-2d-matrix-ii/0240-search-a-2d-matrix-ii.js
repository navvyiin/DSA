var searchMatrix = function(matrix, target) {
    if (!matrix.length || !matrix[0].length) return false;

    let row = 0;
    let col = matrix[0].length - 1;

    while (row < matrix.length && col >= 0) {
        const value = matrix[row][col];

        if (value === target) {
            return true;
        } else if (value > target) {
            col--;
        } else {
            row++;
        }
    }

    return false;
};
var hammingWeight = function(n) {
    let count = 0;

    while (n !== 0) {
        n = n & (n - 1);  // removes the lowest set bit
        count++;
    }

    return count;
};
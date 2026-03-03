var integerReplacement = function(n) {
    let steps = 0;
    let num = BigInt(n);  // use BigInt to avoid overflow for 2^31 - 1
    
    while (num !== 1n) {
        if (num % 2n === 0n) {
            num /= 2n;
        } else {
            // Special case: 3 should go to 2 (not 4)
            if (num === 3n || num % 4n === 1n) {
                num -= 1n;
            } else {
                num += 1n;
            }
        }
        steps++;
    }
    
    return steps;
};
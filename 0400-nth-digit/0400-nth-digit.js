var findNthDigit = function(n) {
    let digitLength = 1;
    let count = 9;
    let start = 1;
    
    // Determine the digit length group
    while (n > digitLength * count) {
        n -= digitLength * count;
        digitLength++;
        count *= 10;
        start *= 10;
    }
    
    // Determine the actual number that contains the nth digit
    let number = start + Math.floor((n - 1) / digitLength);
    
    // Determine the specific digit within that number
    let digitIndex = (n - 1) % digitLength;
    
    return parseInt(number.toString()[digitIndex]);
};
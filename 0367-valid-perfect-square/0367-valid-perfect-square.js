var isPerfectSquare = function(num) {
    let left = 1, right = num;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const square = mid * mid;

        if (square === num) return true;
        if (square < num) left = mid + 1;
        else right = mid - 1;
    }
    return false;
};
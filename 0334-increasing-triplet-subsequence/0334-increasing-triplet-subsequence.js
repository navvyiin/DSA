var increasingTriplet = function(nums) {
    let first = Infinity;
    let second = Infinity;

    for (let x of nums) {
        if (x <= first) {
            first = x;
        } else if (x <= second) {
            second = x;
        } else {
            return true;
        }
    }

    return false;
};
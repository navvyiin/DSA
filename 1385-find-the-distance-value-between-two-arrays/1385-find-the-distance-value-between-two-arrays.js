var findTheDistanceValue = function(arr1, arr2, d) {
    let count = 0;
    for (let num of arr1) {
        let valid = true;
        for (let val of arr2) {
            if (Math.abs(num - val) <= d) {
                valid = false;
                break;
            }
        }
        if (valid) {
            count++;
        }
    }
    return count;
};
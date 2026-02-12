/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    let totalTank = 0;
    let currentTank = 0;
    let start = 0;

    for (let i = 0; i < gas.length; i++) {
        let diff = gas[i] - cost[i];
        
        totalTank += diff;
        currentTank += diff;

        // If we run out of gas, reset starting point
        if (currentTank < 0) {
            start = i + 1;
            currentTank = 0;
        }
    }

    return totalTank >= 0 ? start : -1;
};
class Solution {
    constructor(w) {
        this.prefix = [];
        this.total = 0;

        for (let weight of w) {
            this.total += weight;
            this.prefix.push(this.total);
        }
    }

    pickIndex() {
        let target = Math.random() * this.total;

        let left = 0, right = this.prefix.length - 1;

        while (left < right) {
            let mid = Math.floor((left + right) / 2);

            if (this.prefix[mid] > target) right = mid;
            else left = mid + 1;
        }

        return left;
    }
}
var ProductOfNumbers = function() {
    this.prefixProducts = [1];
};
ProductOfNumbers.prototype.add = function(num) {
    if (num === 0) {
        this.prefixProducts = [1];
    } else {
        const last = this.prefixProducts[this.prefixProducts.length - 1];
        this.prefixProducts.push(last * num);
    }
};
ProductOfNumbers.prototype.getProduct = function(k) {
    const n = this.prefixProducts.length;
    if (k >= n) {
        return 0;
    }
    return this.prefixProducts[n - 1] / this.prefixProducts[n - 1 - k];
};
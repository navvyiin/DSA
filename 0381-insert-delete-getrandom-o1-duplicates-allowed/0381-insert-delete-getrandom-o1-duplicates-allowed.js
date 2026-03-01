class RandomizedCollection {
    constructor() {
        this.arr = [];                  // stores all values
        this.indices = new Map();       // value -> Set of indices
    }

    insert(val) {
        if (!this.indices.has(val)) {
            this.indices.set(val, new Set());
        }
        const isNew = this.indices.get(val).size === 0;

        this.arr.push(val);
        this.indices.get(val).add(this.arr.length - 1);
        return isNew;
    }

    remove(val) {
        if (!this.indices.has(val) || this.indices.get(val).size === 0) {
            return false;
        }

        // take one index of val
        const idx = this.indices.get(val).values().next().value;
        const lastIndex = this.arr.length - 1;
        const lastVal = this.arr[lastIndex];

        // remove idx from val's set
        this.indices.get(val).delete(idx);

        if (idx !== lastIndex) {
            // move last element into idx
            this.arr[idx] = lastVal;

            // update index set of lastVal
            this.indices.get(lastVal).delete(lastIndex);
            this.indices.get(lastVal).add(idx);
        }

        // remove last element
        this.arr.pop();
        return true;
    }

    getRandom() {
        const i = Math.floor(Math.random() * this.arr.length);
        return this.arr[i];
    }
}
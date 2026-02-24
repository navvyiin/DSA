var PeekingIterator = function(iterator) {
    this.iter = iterator;
    this.peeked = false;
    this.peekVal = null;
};

PeekingIterator.prototype.peek = function() {
    if (!this.peeked) {
        this.peekVal = this.iter.next();
        this.peeked = true;
    }
    return this.peekVal;
};

PeekingIterator.prototype.next = function() {
    if (this.peeked) {
        this.peeked = false;
        return this.peekVal;
    }
    return this.iter.next();
};

PeekingIterator.prototype.hasNext = function() {
    return this.peeked || this.iter.hasNext();
};
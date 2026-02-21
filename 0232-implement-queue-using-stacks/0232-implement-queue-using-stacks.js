class MyQueue {
    constructor() {
        this.inStack = [];
        this.outStack = [];
    }

    // Push element x to the back of queue
    push(x) {
        this.inStack.push(x);
    }

    // Removes the element from the front of queue
    pop() {
        this._moveIfNeeded();
        return this.outStack.pop();
    }

    // Get the front element
    peek() {
        this._moveIfNeeded();
        return this.outStack[this.outStack.length - 1];
    }

    // Return whether the queue is empty
    empty() {
        return this.inStack.length === 0 && this.outStack.length === 0;
    }

    // Move elements only when outStack is empty
    _moveIfNeeded() {
        if (this.outStack.length === 0) {
            while (this.inStack.length > 0) {
                this.outStack.push(this.inStack.pop());
            }
        }
    }
}
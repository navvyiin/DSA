class LFUNode {
    constructor(key, value) {
        this.key = key;
        this.value = value;
        this.freq = 1;
        this.prev = null;
        this.next = null;
    }
}

class LFUDoublyLinkedList {
    constructor() {
        this.head = new LFUNode(0, 0);
        this.tail = new LFUNode(0, 0);
        this.head.next = this.tail;
        this.tail.prev = this.head;
        this.size = 0;
    }

    add(node) {
        node.next = this.head.next;
        node.prev = this.head;
        this.head.next.prev = node;
        this.head.next = node;
        this.size++;
    }

    remove(node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        this.size--;
    }

    removeLast() {
        if (this.size > 0) {
            const node = this.tail.prev;
            this.remove(node);
            return node;
        }
        return null;
    }
}

var LFUCache = function(capacity) {
    this.capacity = capacity;
    this.minFreq = 0;
    this.keyMap = new Map();
    this.freqMap = new Map();
};

LFUCache.prototype.updateFreq = function(node) {
    const freq = node.freq;
    const list = this.freqMap.get(freq);
    list.remove(node);

    if (freq === this.minFreq && list.size === 0) {
        this.minFreq++;
    }

    node.freq++;

    if (!this.freqMap.has(node.freq)) {
        this.freqMap.set(node.freq, new LFUDoublyLinkedList());
    }

    this.freqMap.get(node.freq).add(node);
};

LFUCache.prototype.get = function(key) {
    if (!this.keyMap.has(key)) return -1;

    const node = this.keyMap.get(key);
    this.updateFreq(node);
    return node.value;
};

LFUCache.prototype.put = function(key, value) {
    if (this.capacity === 0) return;

    if (this.keyMap.has(key)) {
        const node = this.keyMap.get(key);
        node.value = value;
        this.updateFreq(node);
        return;
    }

    if (this.keyMap.size === this.capacity) {
        const list = this.freqMap.get(this.minFreq);
        const nodeToRemove = list.removeLast();
        this.keyMap.delete(nodeToRemove.key);
    }

    const newNode = new LFUNode(key, value);
    this.minFreq = 1;

    if (!this.freqMap.has(1)) {
        this.freqMap.set(1, new LFUDoublyLinkedList());
    }

    this.freqMap.get(1).add(newNode);
    this.keyMap.set(key, newNode);
};
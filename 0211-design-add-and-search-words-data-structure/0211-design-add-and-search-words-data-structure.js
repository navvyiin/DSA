class TrieNode {
    constructor() {
        this.children = {};
        this.isEnd = false;
    }
}

var WordDictionary = function() {
    this.root = new TrieNode();
};

WordDictionary.prototype.addWord = function(word) {
    let node = this.root;

    for (const ch of word) {
        if (!node.children[ch]) {
            node.children[ch] = new TrieNode();
        }
        node = node.children[ch];
    }

    node.isEnd = true;
};

WordDictionary.prototype.search = function(word) {

    const dfs = (node, index) => {
        if (index === word.length) {
            return node.isEnd;
        }

        const ch = word[index];

        if (ch === '.') {
            for (const child of Object.values(node.children)) {
                if (dfs(child, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node.children[ch]) {
                return false;
            }
            return dfs(node.children[ch], index + 1);
        }
    };

    return dfs(this.root, 0);
};
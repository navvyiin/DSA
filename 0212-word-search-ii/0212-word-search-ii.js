class TrieNode {
    constructor() {
        this.children = {};
        this.word = null; // store full word at terminal node
    }
}

var findWords = function(board, words) {
    const root = new TrieNode();

    // Build Trie
    for (const word of words) {
        let node = root;
        for (const ch of word) {
            if (!node.children[ch]) {
                node.children[ch] = new TrieNode();
            }
            node = node.children[ch];
        }
        node.word = word;
    }

    const result = [];
    const m = board.length;
    const n = board[0].length;

    const dfs = (i, j, node) => {
        const ch = board[i][j];
        if (!node.children[ch]) return;

        node = node.children[ch];

        if (node.word !== null) {
            result.push(node.word);
            node.word = null; // prevent duplicates
        }

        board[i][j] = '#'; // mark visited

        const directions = [[1,0],[-1,0],[0,1],[0,-1]];
        for (const [dx, dy] of directions) {
            const x = i + dx;
            const y = j + dy;
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] !== '#') {
                dfs(x, y, node);
            }
        }

        board[i][j] = ch; // restore
    };

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            dfs(i, j, root);
        }
    }

    return result;
};
var updateBoard = function(board, click) {
    let m = board.length, n = board[0].length;
    let [r, c] = click;

    if (board[r][c] === 'M') {
        board[r][c] = 'X';
        return board;
    }

    const dirs = [
        [-1,-1],[-1,0],[-1,1],
        [0,-1],        [0,1],
        [1,-1],[1,0],[1,1]
    ];

    function dfs(x, y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] !== 'E') return;

        let mines = 0;

        for (let [dx, dy] of dirs) {
            let nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] === 'M') {
                mines++;
            }
        }

        if (mines > 0) {
            board[x][y] = mines.toString();
        } else {
            board[x][y] = 'B';
            for (let [dx, dy] of dirs) {
                dfs(x + dx, y + dy);
            }
        }
    }

    dfs(r, c);
    return board;
};
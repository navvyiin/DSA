var construct = function(grid) {
    const n = grid.length;

    function build(r, c, size) {
        let first = grid[r][c];
        let same = true;

        for (let i = r; i < r + size && same; i++) {
            for (let j = c; j < c + size; j++) {
                if (grid[i][j] !== first) {
                    same = false;
                    break;
                }
            }
        }

        if (same) {
            return new Node(first === 1, true, null, null, null, null);
        }

        let half = size / 2;

        return new Node(
            true,
            false,
            build(r, c, half),
            build(r, c + half, half),
            build(r + half, c, half),
            build(r + half, c + half, half)
        );
    }

    return build(0, 0, n);
};
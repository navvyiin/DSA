import java.util.*;

class Solution {
    public int minMoves(String[] classroom, int energy) {
        int m = classroom.length;
        int n = classroom[0].length();

        int sr = 0, sc = 0;
        List<int[]> litter = new ArrayList<>();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                char ch = classroom[r].charAt(c);

                if (ch == 'S') {
                    sr = r;
                    sc = c;
                } else if (ch == 'L') {
                    litter.add(new int[]{r, c});
                }
            }
        }

        int k = litter.size();

        if (k == 0) {
            return 0;
        }

        int targetMask = (1 << k) - 1;

        // best[mask][cell] = maximum remaining energy
        // reached at this cell with this set of litter collected.
        int[][] best = new int[1 << k][m * n];

        for (int[] row : best) {
            Arrays.fill(row, -1);
        }

        Queue<State> queue = new ArrayDeque<>();

        int startCell = sr * n + sc;
        best[0][startCell] = energy;
        queue.offer(new State(sr, sc, 0, energy, 0));

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!queue.isEmpty()) {
            State cur = queue.poll();

            if (cur.mask == targetMask) {
                return cur.moves;
            }

            if (cur.energy == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                char cell = classroom[nr].charAt(nc);

                if (cell == 'X') {
                    continue;
                }

                int newEnergy = cur.energy - 1;

                if (cell == 'R') {
                    newEnergy = energy;
                }

                int newMask = cur.mask;

                if (cell == 'L') {
                    for (int i = 0; i < k; i++) {
                        if (litter.get(i)[0] == nr && litter.get(i)[1] == nc) {
                            newMask |= (1 << i);
                            break;
                        }
                    }
                }

                int cellId = nr * n + nc;

                // If we can reach the same state with more energy,
                // this is always a better state.
                if (newEnergy > best[newMask][cellId]) {
                    best[newMask][cellId] = newEnergy;

                    queue.offer(new State(
                        nr,
                        nc,
                        newMask,
                        newEnergy,
                        cur.moves + 1
                    ));
                }
            }
        }

        return -1;
    }

    static class State {
        int r;
        int c;
        int mask;
        int energy;
        int moves;

        State(int r, int c, int mask, int energy, int moves) {
            this.r = r;
            this.c = c;
            this.mask = mask;
            this.energy = energy;
            this.moves = moves;
        }
    }
}
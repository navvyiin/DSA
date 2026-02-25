#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Directions for 8 neighbours
        int dirs[8][2] = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };

        // First pass: mark transitions using encoded states
        // 0 -> 0 : dead stays dead
        // 1 -> 1 : live stays live
        // 1 -> 0 : live dies      => mark as -1
        // 0 -> 1 : dead becomes live => mark as 2
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbours = 0;

                for (auto& d : dirs) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (abs(board[x][y]) == 1)
                            liveNeighbours++;
                    }
                }

                if (board[i][j] == 1) {
                    if (liveNeighbours < 2 || liveNeighbours > 3)
                        board[i][j] = -1; // live -> dead
                } else {
                    if (liveNeighbours == 3)
                        board[i][j] = 2;  // dead -> live
                }
            }
        }

        // Second pass: finalise the states
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};
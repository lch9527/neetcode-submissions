class Solution {
private:
    int direction[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return;
        }

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        queue<pair<int, int>> q;

        // Put every treasure into the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + direction[d][0];
                int nc = c + direction[d][1];

                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols ||
                    grid[nr][nc] != INT_MAX) {
                    continue;
                }

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
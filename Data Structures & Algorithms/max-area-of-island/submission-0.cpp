class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int landsize = 0;
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0) {
            return;
        }

        grid[r][c] = 0;
        landsize++;
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int maxArea = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    landsize = 0;
                    dfs(grid, r, c);
                    maxArea = max(maxArea, landsize);
                }
            }
        }

        return maxArea;
    }
};

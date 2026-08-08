class Solution {
private:
    const int direction[4][2] = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(
            row,
            vector<bool>(col, false)
        );

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (board[i][j] == 'O' && !visited[i][j]) {

                    bool edge = false;

                    vector<pair<int,int>> region;

                    dfs(i, j, board, visited, region, edge);

                    // only flip if whole region does NOT touch edge
                    if (!edge) {
                        for (auto& cell : region) {
                            int r = cell.first;
                            int c = cell.second;

                            board[r][c] = 'X';
                        }
                    }
                }
            }
        }
    }

    void dfs(
        int i,
        int j,
        vector<vector<char>>& board,
        vector<vector<bool>>& visited,
        vector<pair<int,int>>& region,
        bool& edge
    ) {

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return;
        }

        if (board[i][j] == 'X' || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        region.push_back({i, j});

        // current O itself is on border
        if (i == 0 ||
            i == board.size() - 1 ||
            j == 0 ||
            j == board[0].size() - 1) {

            edge = true;
        }

        for (int x = 0; x < 4; x++) {
            int ni = i + direction[x][0];
            int nj = j + direction[x][1];

            dfs(ni, nj, board, visited, region, edge);
        }
    }
};
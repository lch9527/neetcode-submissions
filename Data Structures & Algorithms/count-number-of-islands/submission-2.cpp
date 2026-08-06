class Solution {
    private:
        int ans = 0;
        int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        if( r < 0 || r >= grid.size()||
            c < 0 || c >= grid[0].size()||
            grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';

        for(int i = 0; i<4; i++){
            dfs(grid,direction[i][0] + r, direction[i][1]+c);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
           int ans = 0;
           int row = grid.size();
           int col = grid[0].size();

           for(int i = 0; i<row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i,j);
                    ans++;
                }
                }
           }

           return ans;
    }
};

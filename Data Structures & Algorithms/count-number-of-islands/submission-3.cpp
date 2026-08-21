class Solution {
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int ans = 0;
public:

    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i,j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() ||
        j < 0 || j >= grid[0].size()
        || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';
        for(int x = 0; x < 4; x++){
            dfs(grid, direction[x][0] + i, direction[x][1] + j);
        }
        
        return;
    }
};

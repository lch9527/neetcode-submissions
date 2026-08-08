class Solution {
private:
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pavist(row,vector<bool>(col,false));
        vector<vector<bool>> atvist(row,vector<bool>(col,false));

        for(int i = 0; i<row; i++){
            dfs(heights,i,0, pavist);
            dfs(heights,i,col-1, atvist);
        }

        for (int i = 0; i < col; i++){
            dfs(heights, 0,i, pavist);
            dfs(heights, row-1, i, atvist);
        }

        vector<vector<int>> ans;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(pavist[i][j] && atvist[i][j]){
                    ans.push_back({i,j});
                }
            }
        }


        return ans;

    }

    void dfs(vector<vector<int>>& heights,int i, int j, vector<vector<bool>>& vist){
        if(i < 0 || i >= heights.size()|| j < 0 || j >= heights[0].size()||
             vist[i][j]){
             return;
         }
        int curr = heights[i][j];
        vist[i][j] = true;

        for(int x = 0; x< 4; x++){
            int ni = direction[x][0] + i;
            int nj = direction[x][1] + j;

            if(ni < 0 || ni >= heights.size()|| nj < 0 || nj >= heights[0].size()||
                vist[ni][nj]){
                continue;
            }
            int newland = heights[ni][nj];
            if(curr <= newland){
                dfs(heights, ni,nj,vist);
            }
        }

        return;

    }
};

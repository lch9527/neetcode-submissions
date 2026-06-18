class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int total = 0;
        int time = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    total++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty() && total > 0){
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int trow = r + dir[i][0];
                int tcol = c + dir[i][1];

                if(trow<row && tcol<col &&
                     trow>=0 && tcol>=0 &&
                     grid[trow][tcol]==1){
                        grid[trow][tcol] = 2;
                        total--;
                        q.push({trow, tcol});
                     }
                }
            }
            time++;
        }


        return total==0 ? time : -1;
    }
};

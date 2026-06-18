class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // find Pacific and Atlantic
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> ans;

        queue<pair<int,int>> pQueue;
        queue<pair<int,int>> aQueue;
        vector<vector<bool>> pVisit(
            row, vector<bool>(col,false)
        );
        vector<vector<bool>> aVisit(
            row, vector<bool>(col,false) 
        );

        for (int i = 0; i < row; i++){
            // left for pactific
            pQueue.push({i,0});
            pVisit[i][0] = true;

            // right for Atlantic
            aQueue.push({i,col-1});
            aVisit[i][col-1] = true;
        }

        for (int i = 0; i<col; i++){
            //top for pactific
            pQueue.push({0,i});
            pVisit[0][i] = true;

            //lower for Atlantic
            aQueue.push({row-1,i});
            aVisit[row-1][i] = true;
        }

        bfs(pVisit,heights,pQueue);
        bfs(aVisit,heights,aQueue);

        for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
        if (pVisit[r][c] && aVisit[r][c]) {
            ans.push_back({r, c});
        }
    }
}
return ans;
    }

    void bfs(vector<vector<bool>>& visit, 
            vector<vector<int>>& heights,
            queue<pair<int,int>>& q){
// the function that will update the visit map;
            int row = heights.size();
            int col = heights[0].size();
            int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i = 0; i<4; i++){
                    int nr = r+dir[i][0];
                    int nc = c+dir[i][1];
                    if(nr>=0 && nc>=0 && nr<row && nc<col && !visit[nr][nc] && 
                    heights[nr][nc] >= heights[r][c] ){
                        visit[nr][nc] = true;
                        q.push({nr,nc});
                    } 
                }     
            }
            }
};

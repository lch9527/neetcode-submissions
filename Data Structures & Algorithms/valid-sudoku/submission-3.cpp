class Solution {

private:


public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set<int> col[9], row[9], sub[9];

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                int num = board[i][j];
                int bkey = (i/3) * 3 + (j/3);

                if(num == '.'){
                    continue;
                }
                if(col[i].count(num) ||
                    row[j].count(num)||
                    sub[bkey].count(num)){
                        return false;
                }
                
                col[i].insert(num);
                row[j].insert(num);
                sub[bkey].insert(num);
            
            }
        }
        return true;
    }
};

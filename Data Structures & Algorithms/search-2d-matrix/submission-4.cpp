class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty());
        int l = 0, r = matrix.size() - 1, mid;

        while (l <= r){
            mid = (r - l)/2 + l;
            if(matrix[mid][0] == target){
                return true;
            }
            else if(matrix[mid][0] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        int row = r;
        if (row < 0 || matrix[row][0] > target) return false;

        int subl = 0, subr = matrix[r].size()-1, submid;

        while(subl <= subr){
            submid = (subr - subl)/2 + subl;
            if(matrix[row][submid] == target){
                return true;
            }
            else if (matrix[row][submid] > target){
                subr = submid - 1;
            }
            else{
                subl = submid + 1;
            }
        }

        return false;
    }

};

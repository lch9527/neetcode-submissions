class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1, mid;

        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        while(l <= r){
            mid = (r - l)/2 + l;
            if(matrix[mid][0] == target){
                return true;
            }
            else if(matrix[mid][0] > target){
                r = mid - 1;
            }
            else{
                l = mid+1;
            }
        }

        int row = r;
        if (row < 0 || matrix[row][0] > target) return false;
        l = 0; r = matrix[row].size()-1;
        while(l <= r){
            mid = (r - l)/2 + l;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                r = mid - 1; 
            }
            else{
                l = mid + 1;
            }
        }

        return false;
    }
};

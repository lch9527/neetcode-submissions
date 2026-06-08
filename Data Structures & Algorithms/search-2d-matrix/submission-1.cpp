class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int l = 0, r = matrix.size() - 1;

        // Binary search to find the correct row
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // The row where the target might exist
        int row = r; // `r` will point to the largest valid row index
        if (row < 0 || matrix[row][0] > target) return false;

        // Binary search within the selected row
        int subl = 0, subr = matrix[row].size() - 1;
        while (subl <= subr) {
            int mid = subl + (subr - subl) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                subl = mid + 1;
            } else {
                subr = mid - 1;
            }
        }

        return false; // Target not found
    }
};
class Solution {
public:
    bool searchVector(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;

        int row = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (matrix[mid][0] <= target) {
                row = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (row == -1) {
            return false;
        }

        return searchVector(matrix[row], target);
    }
};
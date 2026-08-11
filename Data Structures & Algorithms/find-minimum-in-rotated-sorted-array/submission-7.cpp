class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() -1;

        if(nums[l] < nums[r] || r < 1){
            return nums[l];
        }

        while(l < r){
            int mid = (r - l)/2 + l;
            if(nums[mid] > nums[l]){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        return nums[r+1];
    }
};

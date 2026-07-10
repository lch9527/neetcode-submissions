class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int ans = INT_MAX;
        while(l <= r){
            if(nums[l] > nums[r]){
                ans = min(nums[r],ans);
                r--;
            }
            else {
                ans = min(nums[l],ans);
                return ans;
            }
        }
        return ans;
    }
};

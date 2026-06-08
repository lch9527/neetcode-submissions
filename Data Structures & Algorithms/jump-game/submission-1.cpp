class Solution {
public:
    bool canJump(vector<int>& nums) {
        int best = nums[0];
        for (int i = 1; i < nums.size(); i++){
            best -= 1;
            if(best < 0){
                return false;
            }
            best = std::max(best, nums[i]);
        }

        return true;
    }
};

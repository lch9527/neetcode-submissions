class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector <pair<int,int>> dp(nums.size(),{1, 1});
        dp[0] = {nums[0], nums[0]};
        int ans = nums[0];

        for(int i = 1; i< nums.size(); i++){
 
            int cur = nums[i];
            int fromMin = dp[i-1].first * nums[i];
            int fromMax = dp[i-1].second * nums[i];

            int curMin = min({cur,fromMin,fromMax});
            int curMax = max({cur,fromMin,fromMax});

            dp[i].first = curMin;
            dp[i].second = curMax;
    
            ans = max(ans, dp[i].second);
        }
        return ans;
    }
};

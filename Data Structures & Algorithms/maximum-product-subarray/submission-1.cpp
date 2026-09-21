class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size());

        // dp[i].first  = minimum product of a subarray ending at i
        // dp[i].second = maximum product of a subarray ending at i

        dp[0] = {nums[0], nums[0]};

        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i];

            int fromMin = dp[i - 1].first * cur;
            int fromMax = dp[i - 1].second * cur;

            dp[i].first = min({
                cur,
                fromMin,
                fromMax
            });

            dp[i].second = max({
                cur,
                fromMin,
                fromMax
            });

            ans = max(ans, dp[i].second);
        }

        return ans;
    }
};
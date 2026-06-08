class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int curEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = std::max(farthest, i + nums[i]);

            if (i == curEnd) {
                ans++;
                curEnd = farthest;
            }
        }

        return ans;
    }
};
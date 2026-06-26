class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int lg = nums.size();

        vector<int> pre(lg);
        vector<int> after(lg);
        vector<int> ans(lg);

        pre[0] = 1;
        after[lg - 1] = 1;

        for (int i = 1; i < lg; i++) {
            pre[i] = nums[i - 1] * pre[i - 1];
        }

        for (int i = lg - 2; i >= 0; i--) {
            after[i] = after[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < lg; i++) {
            ans[i] = pre[i] * after[i];
        }

        return ans;
    }
};
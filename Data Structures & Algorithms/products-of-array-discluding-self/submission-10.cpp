class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size()-1;
        vector<int> pre(length+1);
        vector<int> after(length+1);
        vector<int> ans(length+1);

        

        pre[0] = 1;
        after[length] = 1;

        for(int i = 1; i < length + 1; i++){
            pre[i] = nums[i-1] * pre[i-1];
        }

        for(int i = length-1; i>=0; i--){
            after[i] = after[i+1] * nums[i+1];
        }

        for(int i = 0; i < length+1; i++){
            ans[i] = pre[i] * after[i];
        }

        return ans;
    }
};

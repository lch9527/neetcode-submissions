class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++){
            int tmp_num = target - nums[i];
            if(mp.count(tmp_num)){
                return {mp[tmp_num],i};
            }
            mp.insert({nums[i], i});
        }
        
    
        return {};
    }
};
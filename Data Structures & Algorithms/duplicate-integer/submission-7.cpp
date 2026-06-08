class Solution {
public:
   bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> int_map;
        for(int i = 0; i < nums.size(); i++){
            if(int_map.find(nums[i]) != int_map.end()){
                return true;
            }
            int_map.insert(nums[i]);
        }
        return false;
    }
};
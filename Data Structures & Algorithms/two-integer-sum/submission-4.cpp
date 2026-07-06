class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nmap;

        for(int i = 0; i<nums.size(); i++){
            int find = target - nums[i];
            if(nmap.find(find) != nmap.end()){
                return {nmap[find],i};
            }
            else{
                nmap[nums[i]] = i;
            }
        }

        return {};
    }
};

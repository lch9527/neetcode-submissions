class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nmap;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (nmap.find(need) != nmap.end()) {
                return {nmap[need], i};
            }

            nmap[nums[i]] = i;
        }

        return {};
    }
};
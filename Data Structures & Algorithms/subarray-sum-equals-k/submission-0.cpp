class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;

        // One empty prefix with sum 0
        prefixCount[0] = 1;

        int prefixSum = 0;
        int result = 0;

        for (int num : nums) {
            prefixSum += num;

            int needed = prefixSum - k;

            if (prefixCount.count(needed)) {
                result += prefixCount[needed];
            }

            prefixCount[prefixSum]++;
        }

        return result;
    }
};
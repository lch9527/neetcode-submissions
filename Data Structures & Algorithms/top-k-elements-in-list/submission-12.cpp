class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (int num : nums) {
            frequency[num]++;
        }

        // Index = frequency
        // Value = numbers with that frequency
        vector<vector<int>> bucket(nums.size() + 1);

        for (const auto& [num, freq] : frequency) {
            bucket[freq].push_back(num);
        }

        vector<int> ans;

        for (int freq = nums.size(); freq >= 1; freq--) {
            for (int num : bucket[freq]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
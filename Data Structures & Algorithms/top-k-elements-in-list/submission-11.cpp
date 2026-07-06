class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cmap;

        for (int n : nums) {
            cmap[n]++;
        }

        priority_queue<pair<int, int>> heap;

        for (const auto& [num, freq] : cmap) {
            heap.push({freq, num}); // {frequency, number}
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};
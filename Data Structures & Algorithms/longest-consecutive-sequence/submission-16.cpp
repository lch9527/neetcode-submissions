class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nset(nums.begin(), nums.end());

        int ans = 0;

        for (int num : nset) {
            // Only start from the beginning of a sequence
            if (!nset.count(num - 1)) {
                int current = num;
                int length = 1;

                while (nset.count(current + 1)) {
                    current++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> nmap; // key = number we want to see, value = index that needs it

        for (int i = 0; i < (int)numbers.size(); i++) {
            auto it = nmap.find(numbers[i]);
            if (it != nmap.end()) {
                // found the number someone was waiting for
                return {it->second+1, i+1}; // 0-based indices
            }
            nmap[target - numbers[i]] = i;
        }
        return {};
    }
};

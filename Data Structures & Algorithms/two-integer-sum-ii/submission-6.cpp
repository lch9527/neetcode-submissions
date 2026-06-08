class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> Nmap;
        // key = number, value = index

        for (int i = 0; i < numbers.size(); i++) {
            int need = target - numbers[i];

            if (Nmap.find(need) != Nmap.end()) {
                return {Nmap[need]+1, i+1};
            }

            Nmap[numbers[i]] = i;
        }

        return {};
    }
};
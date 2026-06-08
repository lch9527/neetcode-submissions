class Solution {
public:
    struct ArrayHash {
        size_t operator()(const array<int, 26>& arr) const {
            size_t hash = 0;

            for (int x : arr) {
                hash = hash * 31 + x;
            }

            return hash;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> res;

        for (const string& s : strs) {
            array<int, 26> count{};

            for (char c : s) {
                count[c - 'a']++;
            }

            res[count].push_back(s);
        }

        vector<vector<string>> result;

        for (const auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
    }
};
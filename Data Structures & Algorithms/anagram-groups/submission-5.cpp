class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> resMap;

        for(const string& s : strs){
            vector<int> count(26,0);
            for(const char& c: s){
                count[c-'a'] += 1;
            }
            string key;
            for(const int& i : count){
                key += ',' + to_string(i);
            }
            resMap[key].push_back(s);
        }

         vector<vector<string>> result;
        for (const auto& pair : resMap) {
            result.push_back(pair.second);
        }
        return result;
    }
};

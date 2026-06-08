class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> sorted;

        for(const auto&s : strs){
            string tmps = s;
            sort(tmps.begin(),tmps.end());
            sorted[tmps].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &s : sorted){
            ans.push_back(s.second);
        }

        return ans ;
    }
};

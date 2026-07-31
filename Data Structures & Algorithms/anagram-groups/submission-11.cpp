class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> findSet;
        // key = vector<int> for count of char appear,
        // #1#2#3 for abbccc
        // val = strings have same patten

        for(const string& str : strs){
            vector<int> count(26,0);

            for(const char& c : str){
                count[c - 'a'] ++;
            }
            string key;
            for(const int& i : count){
                key += "#";
                key += to_string(i);
            }
            findSet[key].push_back(str); 
        }

        vector<vector<string>> ans;

        for(const auto&[key, val]: findSet){
           ans.push_back(val);
        }

        return ans;
    }
};

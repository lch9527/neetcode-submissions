class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string>> amap;

    for (const string& s: strs){
        vector<int> count(26,0);

        for(const char& c: s){
            count[c-'a']++;
        }
        string key;
        for(const int& i : count){
            key+="#";
            key+=to_string(i);
        }

        amap[key].push_back(s);

    }
            
    vector<vector<string>> ans;

    for(const auto&[key, val]: amap){
        ans.push_back(val);
    }


    return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> smap;
        //string for key of frequence
        vector<vector<string>> ans;
        for(const string& s: strs){
            vector <int> count(26,0);
            for(const char& c: s){
                count[c-'a'] ++;
            }
            string str;
            for(const int& i : count){
                str+= ','+to_string(i); 
            }
            smap[str].push_back(s);   
        }

        for(auto& key:smap ){
            ans.push_back(key.second);
        }

        return ans;
    }
};

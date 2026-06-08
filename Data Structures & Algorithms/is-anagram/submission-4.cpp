class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> strmap;
        if(s.size()!=t.size()){
            return false;
        }
        for (auto c : s ){
            strmap[c]++;
        }
        for (auto c : t){
            strmap[c]--;
            if(strmap[c] < 0){
                return false;
            }
        }
        return true;
    }
};

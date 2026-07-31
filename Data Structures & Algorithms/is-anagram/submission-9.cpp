class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> countmap;
        if(s.size()!=t.size()){
            return false;
        }

        for(const char& c : s){
            countmap[c]++;
        }

        for(const char& c : t){
            if(countmap[c] == 0){
                return false;
            }
            countmap[c]--;
            if(countmap[c] < 0){
                return false;
            }
        }
    return true;

    }
};

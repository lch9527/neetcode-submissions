class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> cmap;

        for(const char& c : s){
            cmap[c] ++;
        }

        for(const char& c: t){
            cmap[c]--;
        }

        for(const auto&[chars, count]: cmap){
            if(count != 0){
                return false;
            }
        }

        return true;

    }
};

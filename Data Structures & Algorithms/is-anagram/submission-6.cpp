class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        std::unordered_map<char,int> cmap;
        for(int i = 0; i<s.size();i++){
            cmap[s[i]]++;
        }

        for(auto i : t){
            cmap[i]--;
            if(cmap[i]<0){
                return false;
            } 
            
        }

        return true;
    }
};

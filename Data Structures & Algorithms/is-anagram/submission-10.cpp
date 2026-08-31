class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int> scount(26,0);
        vector<int> tcount(26,0);
        for(const int &i : s){
            scount[i-'a'] ++;
        }

        for(const int &i : t){
            tcount[i-'a'] ++;
        }

        return (scount == tcount);
    }
};

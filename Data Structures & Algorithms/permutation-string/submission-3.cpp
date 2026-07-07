class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> count (26,0);
        vector<int> tmpcount (26,0);

        for(int i = 0; i<s1.size(); i++){
            count[s1[i] - 'a']++;
        }

        for(int i = 0; i < s2.size(); i++){
            tmpcount[s2[i] - 'a']++;

            if(i >= (int)s1.size()){
                tmpcount[s2[i-(int)s1.size()] - 'a']--;
            }

            if(tmpcount == count){
                return true;
            }
            
        }

        return false;
    }
};

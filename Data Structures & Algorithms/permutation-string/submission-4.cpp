class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        int l = 0;
        vector<int> win(26,0);
        vector<int> scount(26,0);

        for(int i = 0; i<s1.size(); i++){
            win[s2[i] - 'a']++;
            scount[s1[i] - 'a']++;
        }

        if(win == scount){
            return true;
        }

        for(int r = s1.size(); r < s2.size(); r++){
            win[s2[r] - 'a']++;
            win[s2[l] - 'a']--;
            l++;
            if(win == scount){
                return true;
            }
        }
        return false;
    }
};

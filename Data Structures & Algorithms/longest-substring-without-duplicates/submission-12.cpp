class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lgh = s.length();
        if(lgh < 1){
            return 0;
        }

        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_set<char> cset;

        for(int i = 0; i<lgh; i++){
     
            while(r < lgh &&!cset.count(s[r])){
                cset.insert(s[r]);
                r++;
                ans = max(ans, r-i);
            }

            cset.erase(s[i]);

        }

        return ans;
    }
};

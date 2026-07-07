class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0, r = 0,res = 0;

        while(l < s.size()){
            unordered_map<char,int> cmap;
            int r = l;
            int maxf = 0;
            while(r < s.length()){
                cmap[s[r]]++;
                maxf = max(cmap[s[r]],maxf);
                if((r-l + 1) - maxf <= k){
                    res = max(res, r-l +1);
                }
                r++;
            }
            l++;
        }
        return res;


    }
};

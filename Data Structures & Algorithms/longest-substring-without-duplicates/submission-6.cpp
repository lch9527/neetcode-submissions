class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, ans = 0, r = 0;
        const int n = (int)s.size();
        unordered_set<char> set;

        while(s[r]){
            while(set.count(s[r])){
                set.erase(s[l]);
                ++l;
            }
            set.insert(s[r]);
            ans = max(ans, r-l+1);
            r++;
            }
            

        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, ans = 0;
        const int n = (int)s.size();
        unordered_set<char> set;

        for(int r = 0; r < n; ++r){
            while(set.count(s[r])){
                set.erase(s[l]);
                ++l;
            }
            set.insert(s[r]);
            ans = max(ans, r-l+1);
            }
            

        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
                unordered_set<char> cset;

        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            while (cset.find(s[r]) != cset.end()) {
                cset.erase(s[l]);
                l++;
            }

            cset.insert(s[r]);

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> cmap;

        int l = 0;
        int res = 0;
        int maxf = 0;

        for (int r = 0; r < s.size(); r++) {
            // Add current right character into window
            cmap[s[r]]++;

            // Track the highest frequency character in current/historical window
            maxf = max(maxf, cmap[s[r]]);

            // If replacements needed > k, shrink from left
            while ((r - l + 1) - maxf > k) {
                cmap[s[l]]--;
                l++;
            }

            // Current window is valid
            res = max(res, r - l + 1);
        }

        return res;
    }
};
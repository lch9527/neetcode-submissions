class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1count(26, 0);
        vector<int> s2count(26, 0);

        for (char c : s1) {
            s1count[c - 'a']++;
        }

        int windowSize = s1.size();

        for (int i = 0; i < s2.size(); i++) {
            // Add current character into window
            s2count[s2[i] - 'a']++;

            // If window is too large, remove left character
            if (i >= windowSize) {
                s2count[s2[i - windowSize] - 'a']--;
            }

            // Compare frequency
            if (s1count == s2count) {
                return true;
            }
        }

        return false;
    }
};
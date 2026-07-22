class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) {
            return "";
        }

        unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }

        unordered_map<char, int> window;

        int required = need.size();
        int formed = 0;

        int left = 0;

        int minLength = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char rightChar = s[right];

            // Only track characters that appear in t.
            if (need.count(rightChar)) {
                window[rightChar]++;

                // This character has just reached its required count.
                if (window[rightChar] == need[rightChar]) {
                    formed++;
                }
            }

            // Current window contains everything required by t.
            while (formed == required) {
                int currentLength = right - left + 1;

                if (currentLength < minLength) {
                    minLength = currentLength;
                    minStart = left;
                }

                char leftChar = s[left];

                if (need.count(leftChar)) {
                    // If it was exactly satisfied, removing it
                    // makes the window invalid.
                    if (window[leftChar] == need[leftChar]) {
                        formed--;
                    }

                    window[leftChar]--;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(minStart, minLength);
    }
};
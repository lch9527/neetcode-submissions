class Solution {
public:
    // Encodes:  <len>#<string><len>#<string>...
    string encode(vector<string>& strs) {
        string out;
        for (const auto& str : strs) {
            out += to_string(str.size());
            out += '#';
            out += str;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = (int)s.size();

        while (i < n) {
            // parse length until '#'
            int len = 0;
            while (i < n && s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }
            i++; // skip '#'

            // take next len chars as one string
            ans.push_back(s.substr(i, len));
            i += len;
        }

        return ans;
    }
};

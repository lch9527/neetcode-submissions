class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;

        for (const string& s : strs) {
            ans += to_string(s.size());
            ans += '#';
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            string tmp = s.substr(j + 1, length);
            ans.push_back(tmp);

            i = j + 1 + length;
        }

        return ans;
    }
};
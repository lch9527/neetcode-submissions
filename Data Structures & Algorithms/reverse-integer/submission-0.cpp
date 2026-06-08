class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);

        bool negative = false;

        if (s[0] == '-') {
            negative = true;
            s = s.substr(1); // remove '-'
        }

        std::reverse(s.begin(), s.end());

        long long num = stoll(s);

        if (negative) {
            num = -num;
        }

        if (num < INT_MIN || num > INT_MAX) {
            return 0;
        }

        return (int)num;
    }
};
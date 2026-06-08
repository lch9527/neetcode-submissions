class Solution {
public:

    bool isLetterOrNum(const char& c){
        if (c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9' ||
            c >= 'A' && c <= 'Z'){
                return true;
            }
        return false;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;

        while(l<r){
            if(!isLetterOrNum(s[l])){
                l++;
                continue;
            }
            if(!isLetterOrNum(s[r])){
                r--;
                continue;
            }
            if(tolower(s[l]) ==tolower(s[r])){
                l++;
                r--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isAlph(const char& c){
        return( c >= 'a' && c <= 'z' ||
                c >= 'A' && c <= 'Z' ||
                c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while(l < r){
            if(!isAlph(s[l])){
                l ++;
                continue;
            }
            if(!isAlph(s[r])){
                r --;
                continue;
            }
        
            if(tolower(s[l]) !=tolower(s[r])){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
};

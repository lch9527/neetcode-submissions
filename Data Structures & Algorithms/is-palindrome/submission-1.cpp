class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        std::cout<< s[right];
        while(left < right){
            while(left < right && !alphaNum(s[right])){
                right--;
            }
            while(left < right && !alphaNum(s[left])){
                left++;
            }
            if(tolower(s[left]) == tolower(s[right])){
                left ++;
                right --;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool alphaNum(char c){
        return (c >= 'A' && c <= 'Z' || 
                c >= 'a' && c <= 'z' || 
                c >= '0' && c <= '9');
    }
    
};

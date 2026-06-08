class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        unordered_map<char,char> closeToOpen = {
            {')','('},
            {']','['},
            {'}','{'}
        };

        for(const char& c: s){
            if(!stack.empty() && stack.top() == closeToOpen[c]){
                stack.pop();
                continue;
            }
            else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};

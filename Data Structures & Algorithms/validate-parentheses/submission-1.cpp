class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0){
            return false;
        }
        std::stack<char> cs;
        unordered_map<char,char> valid_map = 
        {
            {']','['},
            {'}','{'},
            {')','('}
        };

        for(const auto&c: s){
            if(valid_map.count(c)){

                if(!cs.empty() && cs.top() == valid_map[c]){
                    cs.pop();
                }
                else{
                    return false;
                }
            }
            else{
                 cs.push(c);
            }

        }

        return cs.empty();

    }
};

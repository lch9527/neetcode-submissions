class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int tsize = tokens.size();

        if(tsize < 1){
            return 0;
        }

        stack<int> nstack;
        for(const string& s : tokens){

            if(s == "+" || s == "-" || s == "/" || s == "*"){
                int a = nstack.top();
                nstack.pop();
                int b = nstack.top();
                nstack.pop();

                if(s == "+"){
                    nstack.push(a + b);
                }
                else if(s == "-"){
                    nstack.push(b - a);
                }
                else if(s == "*"){
                    nstack.push(a * b);
                }
                else{
                    nstack.push(b / a);
                }
            }
            else{
                nstack.push(stoi(s));
            }
            
        }

        return nstack.top();
    }
};

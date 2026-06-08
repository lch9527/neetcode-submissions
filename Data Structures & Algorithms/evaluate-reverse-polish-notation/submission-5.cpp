class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> AnsStack;
        int tnum;

        for(const auto& str : tokens){
            if(str == "+"){
                tnum = AnsStack.top();
                AnsStack.pop();
                tnum = AnsStack.top() + tnum;
                AnsStack.pop();
                AnsStack.push(tnum);
            }
            else if(str == "-"){
                tnum = AnsStack.top();
                AnsStack.pop();
                tnum = AnsStack.top() - tnum;
                AnsStack.pop();
                AnsStack.push(tnum);
            }
            else if(str == "*"){
                tnum = AnsStack.top();
                AnsStack.pop();
                tnum = AnsStack.top() * tnum;
                AnsStack.pop();
                AnsStack.push(tnum);
            }
            else if(str == "/"){
                tnum = AnsStack.top();
                AnsStack.pop();
                tnum = AnsStack.top() / tnum;
                AnsStack.pop();
                AnsStack.push(tnum);
            }
            else{
                AnsStack.push(stoi(str));
            }
        }

        return AnsStack.top();
    }
};

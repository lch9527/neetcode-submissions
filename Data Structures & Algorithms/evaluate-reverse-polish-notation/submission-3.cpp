class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> Nstack;
        for(const string s : tokens){
            if(s == "+"){
               int a = Nstack.top(); Nstack.pop();
               int b = Nstack.top(); Nstack.pop();
               Nstack.push(a+b);
            }
            else if(s == "-"){
                int a = Nstack.top(); Nstack.pop();
                int b = Nstack.top(); Nstack.pop();
                std::cout<< a << b;
                Nstack.push(b-a);
            }
            else if(s == "*"){
                int a = Nstack.top(); Nstack.pop();
                int b = Nstack.top(); Nstack.pop();
                Nstack.push(a*b);
            }
            else if(s == "/"){
                int a = Nstack.top(); Nstack.pop();
                int b = Nstack.top(); Nstack.pop();
                Nstack.push(b/a);
            }
            else{
                Nstack.push(stoi(s));
            }
        }
        return Nstack.top();
    }
};

class MinStack {
private:
    vector<int> st;
    vector<int> minst;
    int minval = INT_MAX;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        minval = min(minval,val);
        minst.push_back(minval);
    }
    
    void pop() {
        st.pop_back();
        minst.pop_back();
         if (minst.empty()) {
            minval = INT_MAX;
        } else {
            minval = minst.back();
        }
    }
    
    int top() {
        return st[(int)st.size()-1];
    }
    
    int getMin() {
        return minst.back();
    }
};

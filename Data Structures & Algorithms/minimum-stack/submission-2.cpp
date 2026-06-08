class MinStack {
private:
    vector<int> NumStock;
    vector<int> MinList;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        NumStock.push_back(val);
        MinList.push_back(MinList.empty()? val: min(MinList.back(),val));
    }
    
    void pop() {
        NumStock.pop_back();
        MinList.pop_back();
    }
    
    int top() {
        return NumStock.back();
    }
    
    int getMin() {
        return MinList.back();
    }
};

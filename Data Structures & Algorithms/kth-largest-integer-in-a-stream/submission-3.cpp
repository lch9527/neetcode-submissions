class KthLargest {
int kth;
priority_queue<int, std::vector<int>, std::greater<int>> que;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;

        for(const int& num : nums){
            que.push(num);

            if(que.size() > kth){
                que.pop();
            }
        }
    }
    
    int add(int val) {
        que.push(val);

        if(que.size() > kth){
            que.pop();
        }

        return que.top();
    }
};

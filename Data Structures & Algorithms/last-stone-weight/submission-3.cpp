class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(const int& s : stones){
            maxHeap.push(s);
        }

        while(maxHeap.size() > 1){
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();

            if(a == b){
                maxHeap.push(0);
                continue;
            }

            int c = a - b;

            maxHeap.push(c);
        }

        return maxHeap.top();
    }
};

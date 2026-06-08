class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> maxHeap;
        int ans;
        for(auto i : nums){
            maxHeap.push(i);
        }

        while (k > 1){
            maxHeap.pop();
            k--;
        }

        return maxHeap.top();

    }
};

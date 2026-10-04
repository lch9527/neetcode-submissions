class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = k;

        priority_queue<pair<int,int>> maxheap;
        vector<int> ans;

        for(int i = 0; i < k; i++){
            maxheap.push({nums[i],i});
        }
        ans.push_back(maxheap.top().first);

        while(r < nums.size()){
            maxheap.push({nums[r],r});
            while(maxheap.top().second < r - k + 1){
                maxheap.pop();
            }
            ans.push_back(maxheap.top().first);
            r++;
        }

        return ans;

    }
};

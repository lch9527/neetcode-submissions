class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cmap;
        //key are number and val are fequence

        for(const int& i : nums){
            cmap[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

        for(const auto& [num,freq]: cmap){
            heap.push({freq,num});
            if (heap.size() > k) heap.pop();
        }

        vector<int> ans;
        for (int i = 0; i<k; ++i){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};

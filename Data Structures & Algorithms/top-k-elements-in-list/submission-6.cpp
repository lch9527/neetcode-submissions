class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> nmap;

        for(const auto&n: nums){
            nmap[n]++;
            //key = num, value = f
        }

        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>> minheap;
        
        for(const auto& i: nmap){
            minheap.push(pair(i.second,i.first));
            if(minheap.size() > k){
                minheap.pop();
            }
        }

        vector<int> ans;
        while(!minheap.empty()){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        return ans;

    }
};

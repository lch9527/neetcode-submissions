class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> nmap;
        for(const int& i: nums){
            nmap[i] ++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> numqueue;
            for(const auto& p: nmap){
                numqueue.push({p.second,p.first});
                if(numqueue.size()>k){
                    numqueue.pop();
                }
            }

        vector<int> ans;
        while(!numqueue.empty()){
            ans.push_back(numqueue.top().second);
            numqueue.pop();
        }
    
        return ans;
    }
};

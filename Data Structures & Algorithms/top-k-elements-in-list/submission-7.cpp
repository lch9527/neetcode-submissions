class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> nmap;
        vector<vector<int>> bucket(nums.size()+1);

        for(const auto& i: nums){
            nmap[i]++;
        }// key = num, value freq 

        for(const auto& i: nmap){
            bucket[i.second].push_back(i.first);
        }
        vector <int> ans;

        for(int i = bucket.size()-1; i>0; --i){
            for(const int& i : bucket[i]){
                ans.push_back(i);
                 if(ans.size()==k){
                return ans;
            }
            }
        }
        return ans;
    }
};

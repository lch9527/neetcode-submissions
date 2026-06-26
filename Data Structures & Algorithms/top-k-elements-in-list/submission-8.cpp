class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> fmap;
    // map that key = num and val = frequence;
    vector<vector<int>> bucket(nums.size()+1);
    // bucket: index are frequency and value are numbers;

    for(const int& i : nums){
        fmap[i]++;
    }

    for(const auto& [key, val] : fmap){
        bucket[val].push_back(key);
    }

    vector<int> ans;
    for (int freq = bucket.size() - 1; freq >= 1; freq--) {
        for (int num : bucket[freq]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }

    }
    return ans;
   

    }
};

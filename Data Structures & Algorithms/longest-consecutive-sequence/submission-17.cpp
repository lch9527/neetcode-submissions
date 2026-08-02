class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1){
            return 0;
        }
        unordered_set<int> nset(nums.begin(), nums.end());
        int ans = 1;
        for(const int&num : nset){
            int length = 0;
            if(!nset.count(num-1)){
                int curr = num;

                while(nset.count(curr)){
                    length++;
                    curr++;
                }
            }
            ans = max(ans,length);

        }

        return ans;
    }
};

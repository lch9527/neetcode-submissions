class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <=0){
            return 0;
        }
        unordered_set<int> nset;
        for(const int& i: nums){
            nset.insert(i);
        }
        int ans = 1;
        for(const int& i: nset){
            if(nset.count(i-1)){
                //is begin
                int start = i, num = 1; 
                while(nset.count(start)){
                    num++;
                    start++;
                }
                ans = max(ans,num);
            }
        }
        return ans;
        
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> numset(nums.begin(), nums.end());
        int longert = 0;
        int tmplong = 0;

        for(int n : nums){
            std::cout<< numset.count(n-1);
            if(!numset.count(n-1)){
                tmplong = 1;
                while(numset.count(n+tmplong)){
                    tmplong++;
                }
                longert = max(tmplong, longert);
            }
            
        }
        return longert;
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//        int max = 0, cur;

//        for(int i: nums){
//         cur =std::max(0,cur);
//         cur += i;
//         max = std::max(cur,max);
//        }

//        return max;
//     }
// };
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int best = nums[0];

        for (int i : nums) {
            cur = std::max(0, cur);
            cur += i;
            best = std::max(best, cur);
        }

        return best;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;

        while(l < r){
            int ret = numbers[l] + numbers[r];
            if(ret == target){
                return {l+1,r+1};
            }
            else if(ret > target){
                r--;
            }
            else{
                l++;
            }
        }
        return {};
    }
};

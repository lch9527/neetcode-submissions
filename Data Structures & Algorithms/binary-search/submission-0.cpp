class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, 
        mid = r / 2;
        while(l <= r){
            if ( nums[mid] == target){
                return mid;
            }
            if ( nums[mid] <  target){
                l = mid + 1;
                mid = (r - l) / 2 + l;
                continue;
            }
            else{
                r = mid - 1;
                mid = l/2;
                continue;
                }
        }

        return -1;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end()),
        mid;

        while (l <= r){
            mid = (r - l)/2 + l;
            if(isAbletoFinish(piles,h,mid)){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return r+1;
    }

    bool isAbletoFinish(vector<int>& piles, int h, int target){
        int tmpnum = 0;
        for(const auto& x: piles){
            tmpnum += (x+ target - 1)/target;
        }
        return tmpnum <= h;
    }
};

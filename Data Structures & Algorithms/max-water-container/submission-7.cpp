class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1,ans = 0;

        while(l < r){
            int tmp =  heights[l] <= heights[r]? heights[l] * (r-l) : heights[r] * (r-l);
            if(heights[l] <= heights[r]){
                l++;
            }
            else{
                r--;
            }
            ans = max(ans,tmp);
        }
        return ans;
    }
};

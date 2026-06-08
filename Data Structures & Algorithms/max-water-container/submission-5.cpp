class Solution { 
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxnum = 0;
        
        while (l < r) {
            int height = min(heights[l], heights[r]);
            int width = r - l;
            maxnum = max(maxnum, height * width);
            
            // Move the pointer pointing to the shorter line
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return maxnum;
    }
};
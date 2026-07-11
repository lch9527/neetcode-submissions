class Solution {
public:
    int trap(vector<int>& height) {
          if (height.empty()) {
            return 0;
        }
        //height = [0,2,0,3,1,0,1,3,2,1]
        // water[i] = min()
        int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            leftMax = std::max(leftMax, height[left]);
            water += leftMax - height[left];
            ++left;
        } else {
            rightMax = std::max(rightMax, height[right]);
            water += rightMax - height[right];
            --right;
        }
    }

    return water;
    }
};

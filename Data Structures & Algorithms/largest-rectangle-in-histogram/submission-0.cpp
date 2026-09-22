class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        // pair = {start index, height}
        vector<pair<int, int>> st;

        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int start = i;

            while (!st.empty() && st.back().second > h) {
                int index = st.back().first;
                int height = st.back().second;
                st.pop_back();

                maxArea = max(maxArea, height * (i - index));

                start = index;
            }

            st.push_back({start, h});
        }

        for (auto [i, h] : st) {
            maxArea = max(maxArea, h * ((int)heights.size() - i));
        }

        return maxArea;
    }
};
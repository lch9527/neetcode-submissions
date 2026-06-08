class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > minHeap;

        vector<vector<int>> ans;

        for (vector<int>& p : points) {
            int dist = GetDistance(p);
            minHeap.push({dist, p});
        }

        while (k > 0 && !minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }

        return ans;
    }

    int GetDistance(vector<int>& point) {
        int x = point[0];
        int y = point[1];

        //return sqrt(x^2 + y^2);
        return x*x+y*y;
    }
};
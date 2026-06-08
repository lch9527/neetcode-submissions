class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < intervals.size(); i++) {
            // If the earliest ending room is free, reuse it
            if (!minHeap.empty() && minHeap.top() <= intervals[i].start) {
                minHeap.pop();
            }

            // Add current meeting's end time
            minHeap.push(intervals[i].end);
        }

        return minHeap.size();
    }
};